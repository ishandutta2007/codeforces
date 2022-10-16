#include <bits/stdc++.h>
using namespace std;
int a[201];
int n, k;
vector <int> g[201];
bool done[201];
int f[201][201];
void dfs(int u){
    done[u]=1;
    for(auto &x: g[u]) if(done[x]){
        swap(x, g[u].back());
        g[u].pop_back();
        break;
    }
    for(int x: g[u]) dfs(x);
    f[u][0]=a[u];
    for(int x: g[u]) f[u][0]+=f[x][k];
    for(int i=1; i<=k; i++){
        for(int x: g[u]){
            int res=f[x][i-1];
            for(int y: g[u]) if(y!=x) res+=f[y][k+1-min(i+1, k+2-i)];
            f[u][i]=max(f[u][i], res);
        }
    }
    for(int i=k-1; i>=0; i--) f[u][i]=max(f[u][i], f[u][i+1]);
}
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1, u, v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    cout<<f[1][0]<<'\n';
}