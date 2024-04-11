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

const int N = 1000000;
map<int, int> dp[N];
int max_depth[N];
int mx[N];
int depth[N];
vector<int> g[N];
int ans[N];

void dfs(int v, int par, int d){
    depth[v] = d;
    dp[v][d] = 1;
    mx[v] = 1;
    max_depth[v] = d;
    for(int to: g[v]){
        if(to == par) continue;
        dfs(to, v, d+1);
        if(dp[v].size() >= dp[to].size()){
            for(auto [x, cnt]: dp[to]){
                if(dp[v].count(x) == 0) dp[v][x] = 0;
                dp[v][x] += cnt;
                int cur = dp[v][x];
                if(chmax(mx[v], cur)) max_depth[v] = x;
                if(cur == mx[v]) chmin(max_depth[v], x);
            }
        }else{
            mx[v] = mx[to];
            max_depth[v] = max_depth[to];
            for(auto [x, cnt]: dp[v]){
                if(dp[to].count(x) == 0) dp[to][x] = 0;
                dp[to][x] += cnt;
                int cur = dp[to][x];
                if(chmax(mx[v], cur)) max_depth[v] = x;
                if(cur == mx[v]) chmin(max_depth[v], x);
            }
            dp[v] = move(dp[to]);
        }
    }
    // cout << v << ' ' << depth[v] << ' ' << mx[v] << endl;
    // for(auto [x, cnt]: dp[v]) cout << x << ":" << cnt << " ";
    // cout << endl;
    ans[v] = max_depth[v]-depth[v];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int x, y; cin >> x >> y; x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, -1, 0);
    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
}