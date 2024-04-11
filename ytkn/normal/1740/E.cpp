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
    vector<vector<int>> g(n);
    for(int i = 1; i < n; i++){
        int p; cin >> p; p--;
        g[p].push_back(i);
    }
    auto dp = vec2d(n, 2, 0);
    int ans = 0;
    function<void(int)> dfs = [&](int v){
        dp[v][1] = 1;
        int sum = 0;
        for(int to: g[v]){
            dfs(to);
            sum += max(dp[to][0], dp[to][1]);
            chmax(dp[v][1], dp[to][1]+1);
        }
        dp[v][0] = sum;
        chmax(ans, sum);
        chmax(ans, dp[v][1]);
    };
    dfs(0);
    // for(int i = 0; i < n; i++) print_vector(dp[i]);
    cout << ans << endl;
}