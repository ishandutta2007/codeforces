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
typedef long long ll;
struct edge{
    int to, idx;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> w(n);
    vector<int> deg(n);
    vector<bool> ok(n);
    vector<bool> used(m);
    vector<vector<edge>> g(n);
    for(int i = 0; i < n; i++) cin >> w[i];
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y; x--; y--;
        deg[x]++;
        deg[y]++;
        g[x].push_back(edge{y, i});
        g[y].push_back(edge{x, i});
    }
    queue<int> que;
    vector<int> ans;
    
    auto process = [&](int u){
        for(edge e : g[u]){
            if(!ok[e.to]){
                deg[e.to]--;
            }
        }
        for(edge e : g[u]){
            if(!ok[e.to] && deg[e.to] <= w[e.to]){
                ok[e.to] = true;
                que.push(e.to);
            }
            if(!used[e.idx]) {
                used[e.idx] = true;
                ans.push_back(e.idx);
            }
        }    
    };

    for(int i = 0; i < n; i++){
        if(deg[i] <= w[i]){
            ok[i] = true;
            que.push(i);
        }
    }

    while(!que.empty()){
        int v = que.front(); que.pop();
        // debug_value(v);
        process(v);
    }

    if(ans.size() == m){
        cout << "ALIVE" << endl;
        reverse(ans.begin(), ans.end());
        for(int x: ans) cout << x+1 << ' ';
        cout << endl;
    }else{
        cout << "DEAD" << endl;
    }
}