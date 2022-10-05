//#pragma GCC diagnostic error "-std=c++11"
//#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define ll long long
//#define mod 998244353
using namespace std;

ll n, m;
int pri[320000], cnp;
bool np[320000];
ll dv[640000], f[640000], clo[640000]; int tot;

int P1[320000], P2[320000];
int& POS(ll x){
  return x<=m? P1[x]: P2[n/x];
}

void prep(){
  pri[0]=1;
  for (int i=2;i<=m;++i){
    if (!np[i]) pri[++cnp]=i;
    for (int j=1;j<=cnp&&i*pri[j]<=m;++j){
      np[i*pri[j]]=1;
      if (i%pri[j]==0) break;
    }
  }
}

int getf(int i,int j){
  return clo[j]-i+f[j];
}

int main(){
  cin>>n; m=min(n,(ll)sqrt(n)+10);
  prep();
  for (ll i=1, nex;i<=n;i=nex+1){
    nex=n/(n/i);
    dv[++tot]=n/i;
  }
  reverse(dv+1,dv+tot+1);
  for (int i=1;i<=tot;++i){
    POS(dv[i])=i;
    f[i]=dv[i];// printf(" %lld",dv[i]);
  } //puts("");
  int sp=1;
  for (int i=1;i<=cnp;++i){
    for (;sp<=tot&&(ll)pri[i]*pri[i]>dv[sp];) ++sp;
    for (int j=tot;j>=sp;--j){
      f[j]-=getf(i-1,POS(dv[j]/pri[i]));
      clo[j]=i;
      //printf(" (%d,%d:%lld)",i,j,f[j]);
    }
    //puts("");
  }
  ll ans=0;
  for (int i=1;i<=cnp;++i){
    if ((ll)pri[i]*pri[i]>n) break;
    int po=POS(n/pri[i]);
    ans+=clo[po]+getf(clo[po],po)-i-1;
    //printf(" %d %lld\n",i,clo[po]+getf(clo[po],po));
  }
  cerr<<ans<<endl;
  for (int i=1;i<=cnp;++i)
    if ((ll)pri[i]*pri[i]*pri[i]<=n){
      ++ans;
    }else{
      break;
    }
  cout<<ans<<endl;
}