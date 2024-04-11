#include<bits/stdc++.h>
using namespace std;

#define N 4202000
int n, m, fl[N], dft, dfn[N], low[N], bel[N], cnt[N], blt, ans;
int st[N], tp;

void dfs(int x,int fff){
  dfn[x]=low[x]=++dft;
  st[++tp]=x;
  int y;
  for (int i=0;i<n;++i)
    if (x>>i&1){
      y=x^(1<<i);
      if (!dfn[y]){
	dfs(y,x);
	low[x]=min(low[x],low[y]);
      }else{
	if (!bel[y]) low[x]=min(low[x],dfn[y]);
      }
    }
  if (fl[x]){
    y=((1<<n)-1)^x;
    if (!dfn[y]){
      dfs(y,x);
      low[x]=min(low[x],low[y]);
    }else{
      if (!bel[y]) low[x]=min(low[x],dfn[y]);
    }
  }
  if (dfn[x]==low[x]){
    ++blt;
    for (;;){
      bel[st[tp]]=blt;
      if (st[tp--]==x) break;
    }
  }
}

int main(){
  cin>>n>>m; int x;
  for (;m--;) scanf("%d",&x), fl[x]=1;
  dfs((1<<n)-1,0);
  for (int i=0;i<(1<<n);++i)
    if (fl[i]) cnt[bel[i]]=1;
  for (int i=1;i<=blt;++i) ans+=cnt[i];
  cout<<ans<<endl;
}