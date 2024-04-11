#include <bits/stdc++.h>
using namespace std;
int n, m;
int p2[300001];
vector <int> g[300001];
bool done[300001][2];
vector <int> v;
void dfs(int u, bool b){
    done[u][b]=1;
    v.push_back(u);
    for(int v: g[u]) if(!done[v][!b]) dfs(v, !b);
}
const int base=998244353;
void solve(){
    cin>>n>>m;
    for(int i=1; i<=n; i++) g[i].clear();
    for(int i=1, u, v; i<=m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    long long ans=1;
    for(int i=1; i<=n; i++) done[i][0]=done[i][1]=0;
    for(int i=1; i<=n; i++) if((!done[i][0])&&(!done[i][1])){
        v.clear();
        dfs(i, 0);
        int cnt=0;
        for(int x: v){
            if(done[x][0]&&done[x][1]) ans=0;
            cnt+=done[x][0];
        }
        (ans*=p2[cnt]+p2[v.size()-cnt])%=base;
    }
    cout<<ans<<'\n';
}
int main(){
    p2[0]=1;
    for(int i=1; i<=300000; i++) p2[i]=(p2[i-1]*2)%base;
    int t;
    cin>>t;
    while(t--) solve();
}