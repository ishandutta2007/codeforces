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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll h_max = *max_element(h.begin(), h.end());
    int r = -1;
    for(int i = 0; i < n; i++){
        if(h[i] == h_max){
            r = i;
        }
    }
    vector<ll> mx(n);
    ll ans = 0;
    function<void(int,int)> dfs = [&](int v, int par){
        ll max_ch = 0;
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
            chmax(max_ch, mx[to]);
        }
        if(v == r && g[v].size() > 1){
            vector<ll> mxs;
            for(int to: g[v]){
                mxs.push_back(mx[to]);
            }
            sort(mxs.begin(), mxs.end(), greater<ll>());
            ans += h_max*2 - (mxs[0]+mxs[1]);
        }else{
            if(v == r) ans += h_max;
            if(max_ch < h[v]){
                ans += h[v]-max_ch;
                mx[v] = h[v];
            }else{
                mx[v] = max_ch;
            }
        }
    };
    dfs(r, -1);
    cout << ans << endl;
}