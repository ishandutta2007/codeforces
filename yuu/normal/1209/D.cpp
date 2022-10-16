#include <bits/stdc++.h>
using namespace std;
int n, k;
int r[100001];
int root(int u){
  if(r[u]<0) return u;
  return r[u]=root(r[u]);
}
void unite(int u, int v){
  u=root(u);
  v=root(v);
  if(u==v) return;
  if(r[u]>r[v]) swap(u, v);
  r[u]+=r[v];
  r[v]=u;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin>>n>>k;
  for(int i=1; i<=n; i++) r[i]=-1;
  for(int i=1; i<=k; i++){
    int x, y;
    cin>>x>>y;
    unite(x, y);
  }
  for(int i=1; i<=n; i++) if(i==root(i)){
    int c=-r[i];
    if(c==1) continue;
    k-=c-1;
  }
  cout<<k<<'\n';
}