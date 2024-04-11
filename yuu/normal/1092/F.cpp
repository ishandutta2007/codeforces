#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
vector <int> g[200001];
bool done[200001];
long long f[200001];
long long d[200001];
void dfs(int u){
    done[u]=1;
    for(int &v: g[u]) if(done[v]){
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    d[u]=a[u];
    for(int v: g[u]){
        dfs(v);
        d[u]+=d[v];
        f[u]+=f[v]+d[v];
    }
}
long long ans=0;
void make(int u, long long w, long long cost){
    ans=max(ans, cost);
    for(int v: g[u]) make(v, w+d[u]-d[v], cost+w+d[u]-d[v]*2);
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    {
        int u, v;
        for(int i=1; i<n; i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    dfs(1);
    make(1, 0, f[1]);
    cout<<ans<<'\n';
}