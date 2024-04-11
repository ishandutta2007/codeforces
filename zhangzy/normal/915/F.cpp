#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[1001000],fa[1001000],sz[1001000];
vector<int>G[1001000],v[1001000];
ll ans,t,an;

int GF(int x){
  return fa[x]==x? x: fa[x]=GF(fa[x]);
}

void onion(int x,int y){
  sz[GF(x)]+=sz[GF(y)];
  fa[GF(y)]=GF(x);
}

void doit(int now,int fl){
  for (auto x:v[now]){
    fa[x]=x; sz[x]=1; t=an=0;
    for (auto y:G[x]) if (fa[y]){
        an+=t*sz[GF(y)]; t+=sz[GF(y)];
        onion(x,y);
      }
    ans+=fl*(an+t)*now;
  }
}

int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i)
    scanf("%d",&a[i]), v[a[i]].push_back(i);
  for (int i=n,x,y;--i;)
    scanf("%d%d",&x,&y), G[x].push_back(y), G[y].push_back(x);
  
  for (int i=1;i<=1e6;++i) doit(i,1);
  memset(fa,0,sizeof fa);
  memset(sz,0,sizeof sz);
  for (int i=1e6;i;--i) doit(i,-1);
  cout<<ans;
}