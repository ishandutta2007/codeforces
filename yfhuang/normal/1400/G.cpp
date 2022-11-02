#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

const int mod = 998244353;
const int maxn = 1e6 + 5;

int fac[maxn], inv[maxn];

int qpow(int a, int n){
    int ret = 1;
    while(n > 0){
        if(n & 1){
            ret = 1LL * ret * a % mod;
        }
        a = 1LL * a * a % mod;
        n >>= 1;
    }
    return ret;
}

void pre_comb(){
    fac[0] = 1;
    for(int i = 1;i < maxn;i++){
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    inv[maxn - 1] = qpow(fac[maxn - 1], mod - 2);
    for(int i = maxn - 2;i >= 0;i--){
        inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}

int comb(int n, int m){
    if(m > n or m < 0) return 0;
    return 1LL * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

int n, m;
vector<int> l, r;
vector<vector<int>> adj;
vector<vector<int>> components;
vector<vector<vector<int>>> component_dp;

bool edge_exists(int a, int b){
    return binary_search(adj[a].begin(), adj[a].end(), b);
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    dsu d(n);
    l.resize(n);
    r.resize(n);
    adj.assign(n, {});
    for(int i = 0;i < n;i++){
        cin >> l[i] >> r[i];
    }
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b); 
        adj[b].push_back(a);
        d.merge(a, b);
    }
    for(int i = 0;i < n;i++){
        sort(adj[i].begin(), adj[i].end());
    }
    for(auto g : d.groups()){
        if(g.size() > 1){
            components.push_back(g);
        }
    } 
    component_dp.assign(components.size(), {});
    for(int c = 0; c < components.size();c++){
        auto &component = components[c];
        auto &dp = component_dp[c];
        int C = int(component.size());
        vector<vector<bool>> bad(C, vector<bool>(C, false));

        for(int i = 0;i < C;i++){
            for(int j = i + 1;j < C;j++){
                bad[i][j] = edge_exists(component[i], component[j]);
            }
        }

        dp.assign(1 << C, vector<int>(C + 1, 0));

        for(int mask = 0;mask < (1 << C);mask++){
            bool ok = true;
            for(int i = 0;i < C;i++){
                if((mask >> i) & 1){
                    for(int j = i + 1;j < C and ok;j++){
                        if((mask >> j) & 1 and bad[i][j])
                            ok = false;
                    }
                }
            }
            if(ok)
                dp[mask][__builtin_popcount(mask)] = 1;
        }
        for(int bit = 0;bit < C;bit++){
            for(int mask = 0;mask < (1 << C);mask++){
                if(((mask >> bit) & 1) == 0)
                    for(int i = 0;i < C;i++){
                        dp[mask | (1 << bit)][i] += dp[mask][i];
                    }
            }
        }
    }
    vector<int> freq(n + 2, 0);
    for(int i = 0;i < n;i++){
        freq[l[i]]++;
        freq[r[i]+1]--;
    }
    for(int i = 1;i <= n;i++){
        freq[i] += freq[i - 1];
    }
    pre_comb();
    int ans = 0;
    for(int num = 1;num <= n;num++){
        int merc = freq[num];
        vector<int> knapsack(2 * m + 1, 0);
        knapsack[0] = 1;
        int in_component = 0;
        for(int c = 0;c < int(components.size());c++){
            auto & component = components[c];
            int C = int(component.size());
            int mask = 0;

            for(int i = 0;i < C;i++){
                if(l[component[i]] <= num and num <= r[component[i]])
                    mask |= (1 << i);
            }
            in_component += __builtin_popcount(mask);

            for(int count = m - 1;count >= 0;count--){
                for(int add = 1;add <= C;add++){
                    int delta = 1LL * knapsack[count] * component_dp[c][mask][add] % mod;
                    knapsack[count + add] = (knapsack[count + add] + delta) % mod;
                }
            }
        }
        for(int have = 0;have <= m;have++){
            int delta = 1LL * knapsack[have] * comb(merc - in_component, num- have) % mod;
            ans = (ans + delta) % mod;
        }
    }    
    cout << ans << endl;
    return 0;
}