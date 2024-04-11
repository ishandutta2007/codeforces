#include <bits/stdc++.h>
using namespace std;
int n, m, d;
vector <int> g[200001];
vector <int> c, e;
bool done[200001];
void dfs(int u){
    done[u]=1;
    for(int v: g[u]) if(!done[v]){
        dfs(v);
        if(u==1) c.push_back(v);
    }
    else if(u==1) e.push_back(v);
}
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
    cin>>n>>m>>d;
    for(int i=1, u, v; i<=m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(g[1].size()<d){
        puts("NO");
        return 0;
    }
    dfs(1);
    if(c.size()>d){
        puts("NO");
        return 0;
    }
    puts("YES");
    g[1]=c;
    while(g[1].size()<d){
        g[1].push_back(e.back());
        e.pop_back();
    }
    for(int i=1; i<=n; i++) done[i]=0;
    bfs(1);
}