#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector <int> g[200001];
bool done[200001];
bool done2[200001];
void dfs(bool *done, int u){
  done[u]=1;
  for(int v: g[u]) if(!done[v]) dfs(done, v);
}
void solve(){
  // cerr<<"OK\n";
  cin>>n>>m>>a>>b;
  for(int i=1; i<=n; i++) g[i].clear();
  for(int i=1; i<=n; i++) done[i]=0;
  for(int i=1; i<=n; i++) done2[i]=0;
  for(int i=1, u, v; i<=m; i++){
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  done[b]=1;
  dfs(done, a);
  done2[a]=1;
  dfs(done2, b);
  long long cnt1=0;
  long long cnt2=0;
  for(int i=1; i<=n; i++) if(done[i]&&(!done2[i])) cnt1++;
  for(int i=1; i<=n; i++) if(done2[i]&&(!done[i])) cnt2++;
  cout<<cnt1*cnt2<<'\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
  int t;
  cin>>t;
  while(t--) solve();
}