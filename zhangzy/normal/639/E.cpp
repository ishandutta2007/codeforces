#include<bits/stdc++.h>
using namespace std;

#define db double
#define ll long long

ll n, p[151000], t[151000], l[151000], r[151000], blt;
int id[151000], bel[151000];
db sumt;
bool cmp(int i,int j){
  return t[i]*p[j]<t[j]*p[i];
}
bool cmpp(int i,int j){
  return p[i]<p[j];
}

bool chk(db c){
  db mx=-1e100;
  int las=1;
  for (int i=1;i<=n;++i){
    if (p[id[i]]!=p[id[i-1]]){
      for (int j=las;j<i;++j){
        int x=id[j];
        db tmp=p[x]*(1-(l[bel[x]]+t[x])/sumt*c);
        mx=max(mx,tmp);
      }
      las=i;
    }
    {
      int x=id[i];
      db tmp=p[x]*(1-(r[bel[x]])/sumt*c);
      if (tmp<mx) return 0;
    }
  }
  return 1;
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) cin>>p[i];
  for (int i=1;i<=n;++i) cin>>t[i];
  for (int i=1;i<=n;++i) sumt+=t[i];
  for (int i=1;i<=n;++i) id[i]=i;
  sort(id+1,id+n+1,cmp);
  ll now=t[id[1]], pre=0; int las=1;
  for (int i=2;i<=n+1;++i){
    // printf("%d\n",id[i-1]);
    if (i<=n&&!cmp(id[i-1],id[i])){
      now+=t[id[i]];
    }else{
      ++blt; l[blt]=pre; r[blt]=pre+=now;
      for (int j=las;j<i;++j){
        bel[id[j]]=blt;
      }
      now=t[id[i]]; las=i;
    }
  }
  // for (int i=1;i<=n;++i){
  //   printf(" %d %lld %lld\n",bel[i],l[bel[i]],r[bel[i]]);
  // }
  sort(id+1,id+n+1,cmpp);
  db l=0, r=1;
  for (int T=60;T--;){
    db mid=(l+r)/2;
    if (chk(mid)){
      l=mid;
    }else{
      r=mid;
    }
  }
  printf("%.10lf\n",l);
}