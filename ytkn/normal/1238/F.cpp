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
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    auto dp = vec2d(n, 2, 0);
    function<void(int, int)> dfs = [&](int v, int par){
        int sum = 0;
        vector<int> gains;
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
            gains.push_back(dp[to][1]-dp[to][0]);
            sum += dp[to][0];
        }
        dp[v][0] = 1;
        dp[v][1] = 1;
        if(gains.empty()) return;
        sort(gains.begin(), gains.end(), greater<int>());
        int cnt_par = v == 0 ? 0 : 1;
        if(gains.size() >= 2){
            chmax(ans, 1+sum+gains[0]+gains[1]+cnt_par);
        }
        dp[v][1] = 1+sum+gains[0];
        chmax(ans, dp[v][0]+cnt_par);
        chmax(ans, dp[v][1]+cnt_par);
        // cout << v << ":"; print_vector(dp[v]);
    };
    dfs(0, -1);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}