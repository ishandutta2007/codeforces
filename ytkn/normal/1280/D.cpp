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

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    vector<ll> a(n), b(n), c(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) c[i] = b[i]-a[i];
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<vector<int>> max_win(n);
    vector<vector<ll>> max_root(n);
    function<void(int, int)> dfs = [&](int v, int par){
        max_win[v] = {0};
        max_root[v] = {c[v]};
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
            int m = max_win[v].size() + max_win[to].size()-1;
            vector<int> w(m+1, -1);
            vector<ll> rt(m+1);
            for(int l = 0; l < max_win[v].size(); l++){
                for(int r = 0; r < max_win[to].size(); r++){
                    // 
                    if(w[l+r] == max_win[v][l]+max_win[to][r]){
                        chmax(rt[l+r], max_root[v][l]+max_root[to][r]);
                    }else if(w[l+r] < max_win[v][l]+max_win[to][r]){
                        w[l+r] = max_win[v][l]+max_win[to][r];
                        rt[l+r] = max_root[v][l]+max_root[to][r];
                    }
                    // 
                    int next_win = max_win[v][l]+max_win[to][r];
                    if(max_root[to][r] > 0) next_win++;
                    if(w[l+r+1] == next_win){
                        chmax(rt[l+r+1], max_root[v][l]);
                    }else if(w[l+r+1] < next_win){
                        w[l+r+1] = next_win;
                        rt[l+r+1] = max_root[v][l];
                    }
                }
            }
            max_root[v] = rt;
            max_win[v] = w;
        }
    };
    dfs(0, -1);
    int ans = max_win[0][m-1];
    // print_vector(max_win[0]);
    if(max_root[0][m-1] > 0) ans++;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}