#include <bits/stdc++.h>
using namespace std;
int n, m;
int u[200000];
int v[200000];
bool done[200001];
int c[200001];
vector <int> g[200001];
bool dfs(int u, int co){
    c[u]=co;
    done[u]=1;
    for(int v: g[u]) if(!done[v]){
        if(!dfs(v, 1-co)) return 0;
    }
    else if(c[u]==c[v]) return 0;
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>u[i]>>v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    if(!dfs(1, 0)){
        puts("NO");
        return 0;
    }
    puts("YES");
    for(int i=0; i<m; i++) cout<<c[u[i]];
}