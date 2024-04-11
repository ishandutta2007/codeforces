#include<bits/stdc++.h>
using namespace std;

int n, x, f[303000], g[303000][9], h[303000][9], mu[303000];

int main(){
  cin>>n;
  for (;n--;) scanf("%d",&x), f[x]=1;
  n=3e5;
  for (int i=1;i<=n;++i){
    mu[i]=(i==1)-mu[i];
    for (int j=i+i;j<=n;j+=i)
      mu[j]+=mu[i];
  }
  for (int i=n;i>=1;--i){
    f[i]= f[i]? 1: 8;
    for (int j=i+i;j<=n;j+=i){
      g[i][f[j]]++;
      memset(h[j],0,sizeof h[j]);
    }
    for (int j=i+i;j<=n;j+=i)
      for (int k=j;k<=n;k+=j)
        for (int t=0;t<9;++t)
          h[k][t]+= mu[j/i]*g[j][t];
    for (int j=i+i;j<=n;j+=i)
      for (int t=0;t<9;++t)
        if (g[i][t]+h[j][t])
          f[i]=min(f[i],t+f[j]);
    g[i][f[i]]++;
  }
  cout<<(f[1]==8? -1: f[1])<<endl;
}