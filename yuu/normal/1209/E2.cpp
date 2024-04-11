#include <bits/stdc++.h>
using namespace std;
int n, m;
deque <int> col[2001];
int f[1<<12];
int g[1<<12];
void backtrack(int id, int m, int u, int s){
  if(u==n){
    g[m]=max(g[m], s);
  }
  else{
    backtrack(id, m*2, u+1, s);
    backtrack(id, m*2+1, u+1, s+col[id][u]);
  }
}
void solve(){
  cin>>n>>m;
  for(int i=0; i<m; i++) col[i].clear();
  for(int i=0; i<n; i++){
    for(int i=0; i<m; i++){
      int x;
      cin>>x;
      col[i].push_back(x);
    }
  }
  vector <pair <int, int>> pos;
  for(int i=0; i<m; i++){
    pos.push_back(make_pair(0, i));
    for(int x: col[i]) pos.back().first=max(pos.back().first, x);
  }
  int smax=1<<n;
  sort(pos.begin(), pos.end());
  reverse(pos.begin(), pos.end());
  while(pos.size()>n) pos.pop_back();
  for(int i=0; i<smax; i++) f[i]=0;
  for(int i=0; i<smax; i++) g[i]=0;
  for(auto p: pos){
    int j=p.second;
    for(int i=0; i<smax; i++) g[i]=0;
    for(int shift=0; shift<n; shift++){
      backtrack(j, 0, 0, 0);
      col[j].push_back(col[j].front());
      col[j].pop_front();
    }
    for(int i=smax-1; i>=0; i--){
      for(int u=i; u>0; u=(u-1)&i) f[i]=max(f[i], f[i^u]+g[u]);
    }
  }
  cout<<f[smax-1]<<'\n';
}
int main(){
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--) solve();
}