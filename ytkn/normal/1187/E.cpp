#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

vector<int> G[200000];
bool used[200000];
ll dp[200000];
ll ch[200000];

void dfs(int v){
    used[v] = true;
    ch[v] = 1;
    dp[v] = 0;
    for(int i = 0; i < G[v].size(); i++){
        if(!used[G[v][i]]){
            dfs(G[v][i]);
            dp[v] += dp[G[v][i]];
            ch[v] += ch[G[v][i]];
        }
    }
    dp[v] += ch[v];
}

int N;

void clear(){
    for(int i = 0; i < N; i++) used[i] = false;
}

void dfs1(int v, int p){
    used[v] = true;
    if(p != -1){
        dp[v] = dp[p]-ch[v]+(N-ch[v]);
    }
    for(int i = 0; i < G[v].size(); i++){
        if(!used[G[v][i]]){
            dfs1(G[v][i], v);
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> N;
    for(int i = 0; i < N-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    dfs(0);
    clear();
    dfs1(0, -1);
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}