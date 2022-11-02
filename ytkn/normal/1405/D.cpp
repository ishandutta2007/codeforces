#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

vector<vector<int>> G;
vector<bool> used;
vector<int> dist;

void dfs(int v, int d){
    used[v] = true;
    dist[v] = d;
    for(int to : G[v]){
        if(!used[to]) dfs(to, d+1);
    }
}

void clear_used(){
    for(int i = 0; i < (int)used.size(); i++) used[i] = false;
}

int diameter(){
    dfs(0, 0);
    int max_dist = 0;
    int u = 0;
    for(int v = 0; v < (int)G.size(); v++){
        if(dist[v] > max_dist){
            max_dist = dist[v];
            u = v;
        }
    }
    clear_used();
    dfs(u, 0);
    max_dist = 0;
    for(int v = 0; v < (int)G.size(); v++){
        if(dist[v] > max_dist){
            max_dist = dist[v];
        }
    }
    return max_dist;
}


void solve(){
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db; a--; b--;
    G = vector<vector<int>>(n);
    used = vector<bool>(n, false);
    dist = vector<int>(n);
    for(int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
   
    if(db <= 2*da){
        cout << "Alice" << endl;
        return;
    }
    int diam = diameter();
    if(diam <= 2*da){
        cout << "Alice" << endl;
        return;
    }
    clear_used();
    dfs(a, 0);
    if(dist[b] <= da){
        cout << "Alice" << endl;
        return;
    }
    cout << "Bob" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
        G.clear();
        used.clear();
        dist.clear();
    }
}