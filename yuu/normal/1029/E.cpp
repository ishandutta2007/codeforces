#include <bits/stdc++.h>
using namespace std;
int f[200001][2][2];
int n;
vector <int> g[200001];
bool done[200001];
void dp(int u){
    done[u]=1;
    for(int &v: g[u]) if(done[v]){
        swap(v, g[u].back());
        g[u].pop_back();
        break;
    }
    for(int v: g[u]) dp(v);
    if(g[u].empty()){
        f[u][0][0]=1e9;
        f[u][0][1]=0;
        f[u][1][0]=1;
        f[u][1][1]=1;
        return;
    }
    else{
        for(int v: g[u]) f[u][1][0]+=min(f[v][0][1], f[v][1][1]);
        for(int v: g[u]) f[u][1][1]+=min(f[v][0][1], f[v][1][1]);
        for(int v: g[u]) f[u][0][1]+=min(f[v][0][0], f[v][1][0]);
        f[u][0][0]=1e9;
        for(int v: g[u]) f[u][0][0]=min(f[u][0][0], f[u][0][1]-min(f[v][0][0], f[v][1][0])+f[v][1][0]);
        f[u][1][1]++;
        f[u][1][0]++;
    }
    //cout<<u<<' '<<f[u][0][0]<<' '<<f[u][1][0]<<' '<<f[u][0][1]<<' '<<f[u][1][1]<<'\n';
}
int ans=0;
int main(){
    cin>>n;
    for(int i=1, u, v; i<n; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dp(1);
    for(int v: g[1]){
        ans+=f[v][1][1]-1;
    }
    cout<<ans<<'\n';
}