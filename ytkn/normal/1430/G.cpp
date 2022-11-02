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


vector<int> dijkstra(int s, vector<vector<int>> G){
    queue<int> que;
    int n = G.size();
    vector<int> d(n, 1e9);
    d[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();que.pop();
        for(int to: G[v]){
            if(d[v] + 1 < d[to]){
                d[to] = d[v] + 1;
                que.push(to);
            }
        }
    }
    return d;
}

void dfs(int v, vector<vector<int>> &g, vector<bool> &seen){
    seen[v] = true;
    for(int to: g[v]){
        if(!seen[to]) dfs(to, g, seen);
    }
}

const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    auto sum = vec2d(n, n, 0);
    vector<vector<int>> g(n), g_inv(n);
    auto reachable = vec2d(n, n, false);
    for(int i = 0; i < m; i++){
        int x, y, w; cin >> x >> y >> w; x--; y--;
        g[x].push_back(y);
        g_inv[y].push_back(x);
        sum[x][y] += w;
    }
    for(int i = 0; i < n; i++) {
        auto seen = vector<bool>(n, false);
        dfs(i, g, seen);
        reachable[i] = seen;
    }
    int mask = (1<<n)-1;
    vector<int> sumsum(1<<n);
    vector<bool> ok_same(1<<n, true);
    vector<bool> ok(1<<n, true);
    for(int s = 0; s < (1<<n); s++){
        for(int i = 0; i < n; i++){
            if(!(s&(1<<i))) continue;
            for(int j = i+1; j < n; j++){
                if(!(s&(1<<j))) continue;
                if(reachable[i][j] || reachable[j][i]) ok_same[s] = false;
            }
        }
        int t = mask-s;
        for(int i = 0; i < n; i++){
            if(!(t&(1<<i))) continue;
            for(int j = 0; j < n; j++){
                if(!(s&(1<<j))) continue;
                if(reachable[i][j]) ok[s] = false;
                sumsum[s] += sum[j][i];
            }
        }
    }
    vector<int> dp(1<<n, inf);
    vector<int> pre(1<<n);
    for(int s = 0; s < (1<<n); s++){
        if(ok[s] && ok_same[s]) dp[s] = sumsum[s];
    }
    auto to_vec = [&](int s){
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) ans.push_back(i);
        }
        return ans;
    };
    for(int s = 0; s < (1<<n); s++){
        if(!ok[s]) continue;
        vector<bool> ok_next(n, true);
        auto v = to_vec(s);
        for(int i = 0; i < n; i++){
            if(s&(1<<i)) {
                ok_next[i] = false;
                continue;
            }
            for(int j: v){
                if(reachable[i][j]) ok_next[i] = false;
            }
        }
        int t = 0;
        for(int i = 0; i < n; i++){
            if(ok_next[i]) t += 1<<i;
        }
        for(int r = t; r > 0; r = (r-1)&t){
            if(!ok_same[r] || !ok[s+r]) continue;
            if(chmin(dp[s+r], dp[s]+sumsum[s])){
                pre[s+r] = s;
            }
        }
    }
    // print_vector(dp);
    // print_vector(sumsum);
    int cur = mask;
    vector<int> ans(n);
    int cnt = 0;
    while(cur != 0){
        int p = pre[cur];
        int s = cur-p;
        auto v = to_vec(s);
        for(int i: v) ans[i] = cnt;
        cnt++;
        cur = p;
    }
    print_vector(ans);
}