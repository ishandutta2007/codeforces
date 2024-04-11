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

const int INCREASING = 0;
const int DECREASING = 1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> t(n);
    for(int i = 0; i < n; i++) cin >> t[i];
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];
    vector<vector<int>> g(n);
    for(int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dp = vec2d(n, 2, inf);
    function<void(int, int)> dfs = [&](int v, int par){
        int cnt_inc = 0;
        int cnt_dec = 0;
        ll sum = 0;
        vector<ll> diff;
        for(int to: g[v]){
            if(to == par) continue;
            dfs(to, v);
            if(h[v] > h[to]) {
                cnt_inc++;
                sum += dp[to][INCREASING];
            }else if(h[v] < h[to]) {
                cnt_dec++;
                sum += dp[to][DECREASING];
            }else{
                sum += dp[to][DECREASING];
                diff.push_back(dp[to][INCREASING]-dp[to][DECREASING]);
            }
        }
        sort(diff.begin(), diff.end());

        if(h[par] >= h[v]){ // increasing
            int m = diff.size();
            ll sum_diff = 0;
            for(int inc = 0; inc <= m; inc++){
                if(inc != 0) sum_diff += diff[inc-1];
                int dec = m-inc;
                int sum_inc = inc+cnt_inc;
                int sum_dec = dec+cnt_dec;
                if(sum_inc > sum_dec){
                    chmin(dp[v][INCREASING], sum + sum_diff + t[v]*sum_dec + t[v]*(sum_inc-sum_dec));
                }else{ 
                    chmin(dp[v][INCREASING], sum + sum_diff + t[v]*sum_inc + t[v]*(sum_dec-sum_inc) + t[v]);
                }
            }
        }
        if(h[par] <= h[v]){ // decreasing
            int m = diff.size();
            ll sum_diff = 0;
            for(int inc = 0; inc <= m; inc++){
                if(inc != 0) sum_diff += diff[inc-1];
                int dec = m-inc;
                int sum_inc = inc+cnt_inc;
                int sum_dec = dec+cnt_dec;
                if(sum_dec > sum_inc){
                    chmin(dp[v][DECREASING], sum + sum_diff + t[v]*sum_inc + t[v]*(sum_dec-sum_inc));
                }else{
                    chmin(dp[v][DECREASING], sum + sum_diff + t[v]*sum_dec + t[v]*(sum_inc-sum_dec) + t[v]);
                }  
            }
        }
        if(v == 0){
            int m = diff.size();
            ll sum_diff = 0;
            for(int inc = 0; inc <= m; inc++){
                if(inc != 0) sum_diff += diff[inc-1];
                int dec = m-inc;
                int sum_inc = inc+cnt_inc;
                int sum_dec = dec+cnt_dec;
                if(sum_dec > sum_inc){
                    chmin(dp[v][DECREASING], sum + sum_diff + t[v]*sum_inc + t[v]*(sum_dec-sum_inc));
                }else{
                    chmin(dp[v][DECREASING], sum + sum_diff + t[v]*sum_dec + t[v]*(sum_inc-sum_dec));
                }  
            }
        }
    };
    dfs(0, -1);
    cout << *min_element(dp[0].begin(), dp[0].end()) << endl;
}