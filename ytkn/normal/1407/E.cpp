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

struct edge{
    int to, c;
    edge(int to, int c): to(to), c(c) {}
};

using P = pair<int, int>;
const int inf = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> dist(n, inf);
    vector<int> ans(n, -1);
    ans[n-1] = 0;
    dist[n-1] = 0;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, t; cin >> u >> v >> t; u--; v--;
        g[v].push_back(edge(u, t));
    }
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, n-1));
    while(!que.empty()){
        auto [d, v] = que.top(); que.pop();
        if(d != dist[v]) continue;
        for(edge e: g[v]){
            if(ans[e.to] == -1){
                ans[e.to] = e.c^1;
            }else{
                if(ans[e.to] == e.c){
                    if(chmin(dist[e.to], dist[v]+1)){
                        que.push(P(dist[e.to], e.to));
                    }
                }
            }
        }
    }
    if(dist[0] == inf){
        cout << -1 << endl;
    }else{
        cout << dist[0] << endl;
    }
    for(int i = 0; i < n; i++){
        if(ans[i] == -1) ans[i] = 0;
    }
    for(int x: ans) cout << x;
    cout << endl;
}