#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll K(ll x,int y=mod-2){
  ll t=1;
  for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod;
  return t;
}

int k, n[2], tot, ans;
int c[2][202000], d[2][2][202000];

inline void U(int &x,int y){
  x+=y; if (x>=mod) x-=mod;
}

struct L{
  int l, r, type;
}a[202000], now;
int R[202000];
bool cmp(L u,L v){
  return u.r<v.r;
}

ll que(int *c,int x){
  int t=0;
  for (;x;x-=x&-x) U(t,c[x]);
  return t;
}
int add(int *c,int x,int v){
  for (;x<=tot;x+=x&-x) U(c[x],v);
}

map<int,int>mx; int tp;

int main(){
  cin>>k>>n[0]>>n[1]; ans=K(2,k);

  for (int t=0,x,y;t<2;++t){
    mx.clear(); tp=0;
    for (int i=1;i<=n[t];++i) {
      scanf("%d%d",&x,&y); mx[y]=max(mx[y],x);
    }
    for (auto o:mx)
      if (o.second>tp)
        tp=o.second, a[++tot]=(L){o.second,o.first,t};
  }

  sort(a+1,a+tot+1,cmp);
  for (int i=1;i<=tot;++i) R[i]=a[i].r;
  
  for (int i=1;i<=tot;++i){
    now=a[i];
    int p=lower_bound(R+1,R+tot+1,now.l)-R-1;
    for (int j=0;j<2;++j){

      int res=0, t;
      U(res, que(c[!j],p) *K(K(2,k-now.l+1))%mod );
      U(res, (que(d[now.type][!j],i-1)-que(d[now.type][!j],p) +mod)%mod );

      if (j) U(res,K(2,now.l-1));
      t= res*K(2,k-now.r)%mod;

      U(ans,j? mod-t: t);
      add(c[j],i,t);
      add(d[now.type][j],i,res);
    }
  }
  cout<<ans<<endl;
}