#include<bits/stdc++.h>
using namespace std;

int n, m, ans;
map<int,int>f[101000];
map<int,int>::iterator it, nex;
#define se second

int cal(int x,int v){
  it=f[x].upper_bound(v);
  return (--it)->se+1;
}
void ins(int x,int v,int an){
  it=f[x].upper_bound(v);
  if ((--it)->se>=an) return;
  for (++it;it!=f[x].end()&&it->se<=an;it=nex){
    nex=it; ++nex;
    f[x].erase(it);
  }
  f[x][v]=an;
}

int main(){
  cin>>n>>m;
  for (int i=1;i<=n;++i) f[i][-233]=0;
  int u, v, w;
  for (int i=1;i<=m;++i){
    scanf("%d%d%d",&u,&v,&w);
    int t=cal(u,w); ans=max(ans,t);
    ins(v,w+1,t);
  }
  cout<<ans;
}