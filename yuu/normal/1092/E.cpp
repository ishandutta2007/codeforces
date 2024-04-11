#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> g[1001];
vector <pair <int, int>> v;
int done[1001];
int trace[1001];
int f[1001];
int ans=0;
void find(int u){
    queue <int> q;
    q.push(u);
    done[u]=1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v: g[u]) if(!done[v]){
            done[v]=1;
            q.push(v);
        }
    }
    q.push(u);
    done[u]=2;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v: g[u]) if(done[v]!=2){
            done[v]=2;
            trace[v]=u;
            f[v]=f[u]+1;
            q.push(v);
        }
    }
    int dia=f[u];
    while((f[u]-1)*2>=dia) u=trace[u];
    ans=max(ans, dia);
    v.push_back(make_pair(f[u], u));
}
int main(){
    cin>>n>>m;
    {
        int u, v;
        for(int i=1; i<=m; i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for(int i=1; i<=n; i++) if(!done[i]) find(i);
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    if(v.size()>1) ans=max(ans, v[0].first+v[1].first+1);
    if(v.size()>2) ans=max(ans, v[1].first+v[2].first+2);
    cout<<ans<<'\n';
    for(int i=1; i<v.size(); i++) cout<<v[i].second<<' '<<v[0].second<<'\n';
}