#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

bool topological_sort(vector<vector<int>> g, vector<int> &order){
    int n = g.size();
    order.clear();
    vector<bool> used(n, false);
    function<void(int)> dfs = [&](int v){
        used[v] = true;
        for(int to : g[v]){
            if(!used[to]) dfs(to);
        }
        order.push_back(v);
    };
    for(int v = 0; v < n; v++){
        if(!used[v]) dfs(v);
    }
    reverse(order.begin(), order.end());
    vector<int> inv_order(n);
    for(int i = 0; i < n; i++) inv_order[order[i]] = i;
    for(int v = 0; v < n; v++){
        for(int u : g[v]){
            if(inv_order[v] > inv_order[u]) return false;
        }
    }
    return true;
}

vector<vector<int>> combinations(vector<vector<int>> v){
    int n = v.size();
    int mask = 0;
    for(int i = 0; i < n; i++){
        if(v[i].empty()) return {};
        if(v[i].size() == 2) mask += 1<<i;
    }
    vector<vector<int>> ans;
    for(int s = mask; s >= 0; s = (s-1)&mask){
        vector<int> u(n);
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) u[i] = v[i][1];
            else u[i] = v[i][0];
        }
        ans.push_back(u);
        if(s == 0) break;
    }
    return ans;
}

int to_int(char c){
    if('A' <= c && c <= 'Z') return c-'A';
    return 26+(c-'a');
}

int to_char(char x){
    if(x < 26) return 'A'+x;
    else return 'a'+(x-26);
}

void solve(){
    int n; cin >> n;
    vector<string> s(n);
    vector<vector<int>> t(n);
    vector<vector<int>> cnt(n);
    auto indices = vec2d(n, 52, vector<int>());

    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < s[i].size(); j++) {
            char c = s[i][j];
            t[i].push_back(to_int(c));
            indices[i][to_int(c)].push_back(j);
        }
        // print_vector(indices[0][0]);
    }
    for(int i = 0; i < n; i++){
        cnt[i].resize(t[i].size());
        for(int j = 0; j < t[i].size(); j++){
            for(int k = 0; k < j; k++){
                if(t[i][j] == t[i][k]) cnt[i][j]++;
            }
        }
        // print_vector(cnt[i]);
    }
    auto to_idx = [&](int c, int mask){
        return c*(1<<n) + mask;
    };
    auto from_idx = [&](int idx){
        int c = idx/(1<<n);
        int mask = idx%(1<<n);
        return make_pair(c, mask);
    };
    auto vec_to_mask = [&](vector<int> &u){
        int mask = 0;
        for(int i = 0; i < n; i++){
            if(cnt[i][u[i]] == 1) mask += 1<<i;
        }
        return mask;
    };
    int m = 52*(1<<n);
    vector<vector<int>> g(m);
    vector<bool> ok(m);
    for(int c = 0; c < 52; c++){
        // debug_value(c)
        vector<vector<int>> v(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < t[i].size(); j++){
                if(t[i][j] == c) v[i].push_back(j);
            }
        }
        auto w = combinations(v);
        // debug_value(w.size());
        // cout << c << ' ' << w.size() << endl;
        for(auto u: w){
            int idx_from = to_idx(c, vec_to_mask(u));
            ok[idx_from] = true;
            for(int d = 0; d < 52; d++){
                vector<int> to(n, -1);
                bool ok = true;
                for(int i = 0; i < n; i++){
                    for(int j: indices[i][d]){
                        if(j > u[i]) {
                            to[i] = j;
                            break;
                        }
                    }
                    if(to[i] == -1){
                        ok = false;
                        break;
                    }
                }
                if(!ok) continue;
                int idx_to = to_idx(d, vec_to_mask(to));
                g[idx_from].push_back(idx_to);
            }
        }
    }

    vector<int> ord;
    topological_sort(g, ord);
    vector<int> pre(m);
    vector<int> dp(m, 0);
    for(int x: ord){
        if(!ok[x]) continue;
        chmax(dp[x], 1);
        for(int to: g[x]){
            assert(to != x);
            if(chmax(dp[to], dp[x]+1)){
                pre[to] = x;
            }
        }
    }
    int max_len = *max_element(dp.begin(), dp.end());
    if(max_len == 0){
        cout << 0 << endl;
        cout << endl;
        return;
    }
    // debug_value(max_len);
    int cur = -1;
    for(int x: ord){
        if(dp[x] == max_len){
            cur = x;
            break;
        }
    }
    string ans;
    while(true){
        auto [c, _] = from_idx(cur);
        ans += to_char(c);
        if(dp[cur] == 1) break;
        cur = pre[cur];
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}