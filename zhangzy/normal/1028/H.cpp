#include<bits/stdc++.h>
using namespace std;

int n, m, ans[1101000], li[1101000], ri[1101000];
vector<int>opt[202000];
int c[202000], a[202000];

void add(int x,int v){
  for (x=n+1-x;x<=n;x+=x&-x) c[x]=min(c[x],v);
}
int que(int x){
  int t=1e9;
  for (x=n+1-x;x;x-=x&-x) t=min(t,c[x]);
  return t;
}

int wei[5202000][8], f[5202000], lim=5200000;

void gao(int i,int j,int u){
  assert(u<8);
  for (int v=0;v<8;++v)
    if (wei[j][v])
      add(wei[j][v],u+v);
  wei[j][u]=i;
}

int main(){
  f[1]=0;
  for (int i=2;i<=lim;++i){
    if (!f[i]) f[i]=1;
    for (int j=i+i;j<=lim;j+=i)
      f[j]=f[i]+f[j/i];
  }
  cin>>n>>m; memset(c,1,sizeof c);
  for (int i=1;i<=n;++i) scanf("%d",&a[i]);
  for (int i=1;i<=m;++i){
    scanf("%d%d",&li[i],&ri[i]);
    opt[ri[i]].push_back(i);
  }
  for (int i=1;i<=n;++i){
    int x=a[i];
    for (int j=2;j*j<=x;++j)
      for (;x%(j*j)==0;x/=j*j);
    for (int j=1;j*j<=x;++j)
      if (x%j==0){
        gao(i,j,f[x/j]);
        if (j*j!=x) gao(i,x/j,f[j]);
      }
    for (auto o:opt[i]) ans[o]=que(li[o]);
  }
  for (int i=1;i<=m;++i) printf("%d\n",ans[i]);
}