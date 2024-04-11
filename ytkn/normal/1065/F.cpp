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

const int inf = 1e9;

int n, k;

int depth[1000000];
int min_depth[1000000];
vector<int> g[1000000];
int cnt[1000000];
int cnt1[1000000];

void dfs(int v, int d, vector<int> &path){
    depth[v] = d;
    path.push_back(v);
    if(g[v].empty()){
        min_depth[v] = d;
        int sz = path.size();
        if(sz > k){
            cnt[path[sz-k-1]]++;
        }else{
            cnt[path[0]]++;
        }
    }
    
    for(int to: g[v]){
        dfs(to, d+1, path);
        chmin(min_depth[v], min_depth[to]);
    }
    path.pop_back();
}

int dp[1000000][2];

void dfs1(int v){
    bool ok = min_depth[v] < depth[v]+k;
    int sum = cnt[v];
    int max_gain = 0;
    for(int to: g[v]){
        dfs1(to);
        sum += dp[to][0];
        chmax(max_gain, dp[to][1]-dp[to][0]);
    }
    // cout << v << ' ' << ok << ' ' << sum << ' ' << max_gain << endl;
    if(!ok){
        dp[v][1] = sum+max_gain;
    }else{
        dp[v][0] = sum;
        dp[v][1] = sum+max_gain;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        min_depth[i] = inf;
    }
    for(int i = 1; i < n; i++){
        int p; cin >> p; p--;
        g[p].push_back(i);
    }
    vector<int> path;
    dfs(0, 0, path);
    dfs1(0);
    int mx = 0;
    cout << max(dp[0][0], dp[0][1]) << endl;
}