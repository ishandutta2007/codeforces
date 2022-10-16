#include <bits/stdc++.h>
using namespace std;
int n, x, y;
bool done[300001];
int f[300001];
int p[300001];
vector <int> g[300001];
void dfs(int u){
    f[u]=1;
    for(int v: g[u]) if(p[u]!=v){
        p[v]=u;
        dfs(v);
        f[u]+=f[v];
    }
}
int main(){
    cin>>n>>x>>y;
    for(int i=1, u, v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(x);
    long long low=f[y];
    while(p[y]!=x) y=p[y];
    long long high=n-f[y];
    long long ans=n;
    ans*=n;
    ans-=low*high+n;
    cout<<ans<<'\n';
}