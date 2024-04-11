#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> g[200001];
bool done[200001];
queue <int> q;
void bfs(int u){
    q.push(u);
    done[u]=1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v: g[u]) if(!done[v]){
            done[v]=1;
            q.push(v);
            cout<<u<<' '<<v<<'\n';
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1, u, v; i<=m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int best=1;
    for(int i=1; i<=n; i++) if(g[i].size()>g[best].size()) best=i;
    bfs(best);
}