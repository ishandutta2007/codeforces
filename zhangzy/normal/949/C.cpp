#include<bits/stdc++.h>
using namespace std;


int n, m, h, a[101000];

vector<int>G[101000];

int dfn[101000], low[101000], dft, st[101000], tp, bel[101000], blt, die[101000];
vector<int>vec, ans;

void tar(int x){
  dfn[x]=low[x]=++dft;
  st[++tp]=x;
  for (auto y:G[x]){
    if (!dfn[y]){
      tar(y);
      low[x]=min(low[x],low[y]);
      if (bel[y]) die[x]=1;
    }else{
      if (!bel[y])
        low[x]=min(low[x],dfn[y]);
      else
        die[x]=1;
    }
  }
  if (dfn[x]==low[x]){
    vec.clear();
    for (;;){
      vec.push_back(st[tp]);
      if (st[tp--]==x) break;
    }
    int fl=1; ++blt;
    for (auto o:vec) fl&=!die[o], bel[o]=blt;
    if (fl)
      if (vec.size()<ans.size()||!ans.size())
        ans=vec;
  }
}

int main(){
  cin>>n>>m>>h;
  for (int i=1;i<=n;++i) scanf("%d",&a[i]);
  int x,y;
  for (;m--;){
    scanf("%d%d",&x,&y);
    if (a[y]==(a[x]+1)%h) G[x].push_back(y);
    if (a[x]==(a[y]+1)%h) G[y].push_back(x);
  }
  for (int i=1;i<=n;++i) if (!dfn[i]) tar(i);
  sort(ans.begin(),ans.end());
  printf("%d\n",(int)ans.size());
  for (auto o:ans) printf("%d ",o);
}