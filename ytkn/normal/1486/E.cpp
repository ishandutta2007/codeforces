#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
using T = tuple<int, int, int>;
typedef long long ll;
const int INF = 1e9;

struct edge{
    int to, w;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<vector<edge>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        g[u].push_back(edge{v, w});
        g[v].push_back(edge{u, w});
    }
    vector<vector<int>> dist(n, vector<int>(51, INF));
    priority_queue<T, vector<T>, greater<T>> que;
    dist[0][0] = 0;
    que.push(T(0, 0, 0));
    while(!que.empty()){
        auto [d, v, w] = que.top(); que.pop();
        if(d > dist[v][w]) continue;
        for(edge e : g[v]){
            if(w == 0){
                if(dist[e.to][e.w] > d+e.w*e.w){
                    dist[e.to][e.w] = d+e.w*e.w;
                    que.push(T(dist[e.to][e.w], e.to, e.w));
                }
            }else{
                if(dist[e.to][0] > d+2*e.w*w+e.w*e.w){
                    dist[e.to][0] = d+2*e.w*w+e.w*e.w;
                    que.push(T(dist[e.to][0], e.to, 0));
                }
            }
            
        }
    }
    for(int i = 0; i < n; i++){
        if(dist[i][0] == INF){
            cout << -1 << endl;
        }else{
            cout << dist[i][0] << endl;
        }
    }
}