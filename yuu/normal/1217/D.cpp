#include <bits/stdc++.h>
const int mx=1e9+7;
using namespace std;
int n, m;
int u[5001];
int v[5001];
bool done[5001];
bool up[5001];
vector <int> g[5001];
bool dfs(int u){
  done[u]=1;
  up[u]=1;
  for(int v: g[u]) if(!done[v]){
    if(dfs(v)) return 1;
  }
  else if(up[v]) return 1;
  up[u]=0;
  return 0;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin>>n>>m;
  for(int i=1; i<=m; i++){
    cin>>u[i]>>v[i];
    g[u[i]].push_back(v[i]);
  }
  int ans=1;
  for(int i=1; i<=n; i++) if(!done[i]) if(dfs(i)){
    ans=2;
    break;
  }
  cout<<ans<<'\n';
  for(int i=1; i<=m; i++){
    if(u[i]<v[i]) cout<<1;
    else cout<<ans;
    cout<<" \n"[i==m];
  }
}