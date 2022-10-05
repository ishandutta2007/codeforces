#include<bits/stdc++.h>
using namespace std;

int n, a[2020], st[2020], en[2020], f[2020][2020], g[2020][2020], ans, tmp[3];

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) cin>>a[i];
  if (n<=2) return 0*printf("%d",n);
  memset(tmp,0,sizeof tmp);
  for (int i=1;i<=n;++i){
    memset(tmp,0,sizeof tmp);
    for (int j=i;j<=n;++j){
      if (a[j]==1){
        f[i][j]=tmp[a[j]]+1;
      }else{
        f[i][j]=max(tmp[1],tmp[2])+1;
      }
      tmp[a[j]]=max(tmp[a[j]],f[i][j]);
      ans=max(ans,f[i][j]);
    }
  }
  for (int i=1;i<=n;++i){
    memset(tmp,0,sizeof tmp);
    for (int j=i;j<=n;++j){
      if (a[j]==2){
        g[i][j]=tmp[a[j]]+1;
      }else{
        g[i][j]=max(tmp[1],tmp[2])+1;
      }
      tmp[a[j]]=max(tmp[a[j]],g[i][j]);
    }
  }
  for (int i=1;i<=n;++i){
    st[i]=max(st[i-1],f[1][i]);
  }
  for (int i=n;i;--i){
    for (int j=i;j<=n;++j)
      en[i]=max(en[i],f[i][j]);
    en[i]=max(en[i],en[i+1]);
  }
  for (int i=1;i<=n;++i){
    for (int j=i;j<=n;++j)
      ans=max(ans,st[i-1]+en[j+1]+g[i][j]);
  }
  cout<<ans<<endl;
}