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
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if(n == 2){
        cout << 1 << endl;
        return;
    }
    auto dp = vec3d(n, 2, 2, n);
    function<void(int, int, int)> dfs = [&](int v, int par, int root){
        vector<int> children;
        for(int to: g[v]){
            if(to == par) continue;
            children.push_back(to);
        }
        if(children.empty()){
            dp[v][0][0] = 0;
            dp[v][1][1] = 1;
        }
        if(children.size() == 1){
            int ch = children[0];
            dfs(ch, v, root);
            dp[v][0][0] = dp[ch][0][0];
            dp[v][1][0] = dp[ch][1][0];
            dp[v][1][1] = min({dp[ch][0][0]+1, dp[ch][1][0]+1, dp[ch][1][1]});
        }
        if(children.size() >= 2){
            for(int ch: children){
                dfs(ch, v, root);
            }
            int max_gain = 0;
            int sum = 0;
            for(int ch: children){
                int mn = min(dp[ch][1][0], dp[ch][1][1]);
                sum += mn;
                chmax(max_gain, mn-dp[ch][0][0]);
            }
            dp[v][1][1] = min(sum, sum-max_gain+1);
            dp[v][1][0] = sum-max_gain;
        }
        
    };
    for(int i = 0; i < n; i++){
        // dp = vec3d(n, 2, 2, n);
        if(g[i].size() != 1) continue;
        dfs(i, -1, i);
        cout << dp[i][1][1] << endl;
        return;
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}