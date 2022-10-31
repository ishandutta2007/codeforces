#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int x[200000], y[200000];
bool used[200000];

set<int> G[200000];
int n, m, k;
int ret[200000];

int ans;

void dfs(int v){
    used[v] = false;
    ans--;
    for(int u : G[v]){
        if(used[u]){
            if(G[u].count(v) > 0) G[u].erase(v);
            if(G[u].size() < k) dfs(u);
        }
    }
    G[v].clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> m >> k;
    ans = n;
    for(int i = 0; i < m; i++){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
        G[x[i]].insert(y[i]);
        G[y[i]].insert(x[i]);
    }
    for(int i = 0; i < n; i++) used[i] = true;
    for(int i = 0; i < n; i++){
        if(used[i] && G[i].size() < k){
            dfs(i);
        }
    }
    ret[m-1] = ans;
    for(int i = m-1; i > 0; i--){
        if(used[x[i]]){
            if(G[x[i]].count(y[i]) > 0) G[x[i]].erase(y[i]);
            if(G[x[i]].size() < k) dfs(x[i]);
        }
        if(used[y[i]]){
            if(G[y[i]].count(x[i]) > 0)G[y[i]].erase(x[i]);
            if(G[y[i]].size() < k) dfs(y[i]);
        }
        ret[i-1] = ans;
    }
    for(int i = 0; i < m; i++) cout << ret[i] << endl;
}