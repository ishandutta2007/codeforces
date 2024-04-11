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

vector<int> g[200000];
int a[200000];
int cumsum[200000];
int ans = 0;
int idx[200000];
set<int> dp[200000];

void dfs(int v, int par, int from_par){
    cumsum[v] = a[v]^from_par;
    dp[idx[v]].insert(cumsum[v]);
    bool changed = false;
    for(int to: g[v]){
        if(to == par) continue;
        dfs(to, v, cumsum[v]);
        if(changed) continue;
        if(dp[idx[to]].size() > dp[idx[v]].size()){
            swap(idx[to], idx[v]);
        }
        for(int x: dp[idx[to]]){
            if(dp[idx[v]].count(x^a[v])){
                changed = true;
                dp[idx[v]].clear();
                break;
            }
        }
        if(changed) continue;
        for(int x: dp[idx[to]]) dp[idx[v]].insert(x);
    }
    if(changed) ans++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        idx[i] = i;
    }
    dfs(0, -1, 0);
    cout << ans << endl;
}