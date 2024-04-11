#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[300001];
vector <int> g[300001];
set <int> all;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=n; i>=1; i--) cin>>p[i];
    for(int i=1, u, v; i<=m; i++){
        cin>>u>>v;
        g[u].push_back(v);
        //g[v].push_back(u);
    }
    int ans=0;
    all.insert(p[1]);
    for(int i=2; i<=n; i++){
        int cnt=0;
        for(int v: g[p[i]]) cnt+=(all.find(v)!=all.end());
        if(cnt==all.size()) ans++;
        else all.insert(p[i]);
    }
    cout<<ans<<'\n';
}