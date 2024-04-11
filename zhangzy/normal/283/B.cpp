#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[202000],en,fa[404000],f[404000];
vector<int>G[404000];
ll bas[404000];

void dfs(int x){
  for (auto y:G[x]){
    f[y]=f[x]+(y/2==1);
    bas[y]=bas[x]+a[y/2];
    dfs(y);
  }
}

int main(){
  cin>>n; en=n+1<<1;
  for (int i=2,x;i<=n;++i){
    scanf("%d",&a[i]);
    if (i+a[i]>n){
      fa[i<<1|0]=en;
      G[en].push_back(i<<1|0);
    }else{
      fa[i<<1|0]=i+a[i]<<1|1;
      G[i+a[i]<<1|1].push_back(i<<1|0);
    }
    if (i-a[i]<1){
      x=en;
      fa[i<<1|1]=x;
      G[x].push_back(i<<1|1);
    }else{
      x=i-a[i]<<1|0;
      fa[i<<1|1]=x;
      G[x].push_back(i<<1|1);
    }
  }
  fa[1<<1|1]=en;
  G[en].push_back(1<<1|1);
  
  memset(f,-1,sizeof f);
  f[en]=0; bas[en]=0;
  dfs(en);
  for (int i=2;i<=n;++i){
    if (~f[i<<1|1]){
      printf("%lld\n",bas[i<<1|1]+(ll)f[i<<1|1]*i+i-1);
    }else{
      puts("-1");
    }
  }
}