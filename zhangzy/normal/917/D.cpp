#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n, G[111][111];
ll a[111][111], b[111][111];

ll K(ll x,int y=mod-2){
  ll t=1;
  for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod;
  return t;
}

int doit(){
  ll res=1;
  for (int i=1;i<n;++i)
    for (int j=1;j<n;++j)
      if (a[i][j]<0)
        a[i][j]+=mod;
  for (int i=1;i<n;++i){
    int p=0;
    for (int k=i;k<n;++k)
      if (a[k][i]){
        p=k; break;
      }
    if (!p) return 0;
    if (p!=i){
      swap(a[i],a[p]); res=mod-res;
    }
    for (int k=i+1;k<n;++k) if (a[k][i]){
      ll bas=K(a[k][i])*a[i][i]%mod;
      res=res*K(bas)%mod;
      for (int j=i;j<n;++j) a[k][j]=(a[k][j]*bas+mod-a[i][j])%mod;
    }
    res=res*a[i][i]%mod;
  }
  return res;
}

void gaosi(){
  for (int i=1;i<=n;++i){
    int p=0;
    for (int k=i;k<=n;++k)
      if (a[k][i]){
        p=k; break;
      }
    swap(a[i],a[p]);
    for (int k=1;k<=n;++k){
      if (i==k||!a[k][i]) continue;
      ll bas=K(a[k][i])*a[i][i]%mod;
      for (int j=1;j<=n+1;++j) a[k][j]=(a[k][j]*bas+mod-a[i][j])%mod;
    }
  }
}

int main(){
  cin>>n;
  int x,y;
  for (int i=n;--i;) cin>>x>>y, G[x][y]=G[y][x]=1;
  for (int k=1;k<=n;++k){
    memset(a,0,sizeof a);
    for (int i=1;i<=n;++i)
      for (int j=1;j<=n;++j)
        if (i!=j){
          a[i][i]-= G[i][j]? a[i][j]=-k: a[i][j]=-1;
        }
    ll tmp=1;
    for (int j=1;j<=n;++j){
      b[k][j]=tmp;
      tmp=tmp*k%mod;
    }
    b[k][n+1]=doit();
  }
  memcpy(a,b,sizeof a); gaosi();
  for (int i=1;i<=n;++i) printf("%I64d ",a[i][n+1]*K(a[i][i])%mod);
}