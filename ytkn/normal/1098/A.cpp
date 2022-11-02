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

const ll inf = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<vector<int>> g(n);
    vector<ll> s(n);
    vector<int> p(n, -1);
    for(int i = 1; i < n; i++){
        cin >> p[i]; p[i]--;
        g[p[i]].push_back(i);
    }
    for(int i = 0; i < n; i++) cin >> s[i];
    vector<int> depth(n);
    bool ok = true;
    function<void(int, int, ll)> dfs = [&](int v, int d, ll mx){
        depth[v] = d;
        if(s[v] != -1 && s[v] < mx){
            ok = false;
        }
        chmax(mx, s[v]);
        for(int to: g[v]){
            dfs(to, d+1, mx);
        }
    };
    dfs(0, 1, 0);
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    vector<bool> f(n);
    for(int i = 1; i < n; i++){
        if(g[i].empty() && depth[i]%2 == 0) f[i] = true;
    }
    vector<vector<int>> h(n);
    for(int i = 0; i < n; i++){
        for(int j: g[i]){
            if(f[j]) continue;
            h[i].push_back(j);
        }
    }
    ll ans = 0;
    function<void(int)> dfs1 = [&](int v){
        if(h[v].empty()){
            ans += s[v];
            return;
        }
        ll min_ch = inf;
        for(int to: h[v]){
            dfs1(to);
            chmin(min_ch, s[to]);
        }
        if(depth[v]%2 == 0){
            s[v] = min_ch;
        }
        ans -= s[v]*(h[v].size()-1);
    };
    dfs1(0);
    cout << ans << endl;
}