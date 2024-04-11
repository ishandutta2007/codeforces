#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,p,A[10100],x,y,b,mod;
vector<int>v;
map<int,int>a;
ll ans,f[10100];
bitset<10001000>fl;

int K(ll x,int y){
  ll t=1;
  for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod;
  return t;
}

int main(){
  cin>>n>>m>>mod; b=p=mod-1;
  for (int i=n;i--;) cin>>A[i];
  for (int i=m;i--;){
    cin>>x; x%=p;
    if (x) b=__gcd(x,b);
  }
  for (int i=1;i*i<=p;++i) if (p%i==0){
      v.push_back(i);
      if (i*i-p) v.push_back(p/i);
  }
  for (int i=n;i--;){
    x=A[i]; y=1;
    for (auto o:v) if (K(x,p/o)==1){
	y=max(y,o*__gcd(p/o,b));
      }
    a[y]=1;
  }
  if (p<=1e7){
    for (auto o:a){
      x=o.first;
      for (register int i=x;i<=p;i+=x)
	if (!fl[i])
	  fl[i]=1, ++ans;
    }
    return 0*printf("%lld\n",ans);
  }
  v.clear();
  for (auto o:a) v.push_back(o.first);
  for (int i=v.size();i--;){
    f[i]=p/v[i];
    for (int j=v.size();--j>i;)
      if (v[j]%v[i]==0)
	f[i]-=f[j];
    ans+=f[i];
  }
  cout<<ans;
}