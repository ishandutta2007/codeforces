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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

using lll = __int128_t;

ll mod_pow(ll a_, ll n, ll mod) {
    lll a = a_;
    lll ans = 1;
    while (n > 0) {
        if (n&1) ans = (ans*a)%mod;
        a = (a*a)% mod;
        n >>= 1;
    }
    return ans;
}

using P = pair<ll, int>;

vector<P> factorize(ll m){
    vector<P> ans;
    ll x = m;
    for(ll a = 2; a*a <= m; a++){
        int cnt = 0;
        while(x%a == 0){
            x /= a;
            cnt++;
        }
        if(cnt != 0) ans.push_back(P(a, cnt));
    }
    if(x != 1) ans.push_back(P(x, 1));
    return ans;
}

ll ans;
vector<ll> tot_facs;

void dfs(const vector<P> &facs, vector<int> &cnt, ll x, ll m, ll tot){
    if(facs.size() == cnt.size()){
        if(m == 1) return;
        // assert(mod_pow(x, tot, m) == 1);
        ll log1 = tot;
        for(ll a: tot_facs){
            if(tot%a == 0 && mod_pow(x, a, m) == 1){
                chmin(log1, a);
                break;
            }
        }
        
        // debug_value(log1);
        ans += tot/log1;
        return;
    }
    int i = cnt.size();
    ll p = facs[i].first;
    for(int j = 0; j <= facs[i].second; j++){
        cnt.push_back(j);
        if(j == 1){
            tot *= p-1;
            m *= p;
        }
        if(j > 1){
            tot *= p;
            m *= p;
        }
        dfs(facs, cnt, x, m, tot);
        cnt.pop_back();
    }
}

ll naive(ll m, ll x){
    UnionFind uf(m);
    for(int i = 0; i < m; i++){
        int nx = (i*x)%m;
        uf.unionSet(i, nx);
    }
    ll ans = 0;
    for(int i = 0; i < m; i++){
        if(uf.root(i) == i) ans++;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    ll m, x; cin >> m >> x;
    auto facs = factorize(m);
    ll tot = m;
    for(auto [p, cnt]: facs) {
        tot /= p;
        tot *= p-1;
    }
    for(ll a = 1; a*a <= tot; a++){
        if(tot%a == 0) {
            tot_facs.push_back(a);
            if(a*a != tot) tot_facs.push_back(tot/a);
        }
    }
    sort(tot_facs.begin(), tot_facs.end());
    // debug_value(tot_facs.size());
    // print_vector(tot_facs);
    vector<int> cnt;
    ans = 1;
    dfs(facs, cnt, x, 1, 1);
    cout << ans << endl;
    // cout << naive(m, x) << endl;
}