#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, a[55], b[55], f[55][5050], g[55][5050], inf;
map<ll,vector<ll> >mp;

void U(ll &x,ll y){
  x=min(x,y);
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) cin>>a[i];
  for (int i=1;i<=n;++i) cin>>b[i];
  for (int i=1;i<=n;++i) mp[-a[i]].push_back(b[i]);
  memset(f,33,sizeof f); swap(inf,f[0][0]);
  for (auto it:mp){
    memset(g,33,sizeof g);
    ll now=-it.first; vector<ll>&the=it.second;
    sort(the.begin(),the.end(),greater<ll>());
    ll cnt=0, las=the.size(), sum=0;
    for (int i=las;i<=n;++i)
      for (int j=0;j<=5000;++j)
	if (f[i][j]!=inf){
	  U(g[i-las+cnt][j+sum],f[i][j]+now*cnt);
	}
    for (auto o:the){
      sum+=o; ++cnt; --las;
      for (int i=las;i<=n;++i)
	for (int j=0;j<=5000;++j)
	  if (f[i][j]!=inf){
	    U(g[i-las+cnt][j+sum],f[i][j]+now*cnt);
	  }
    }
    memcpy(f,g,sizeof f);
  }
  ll ans=inf;
  for (int i=0;i<=n;++i)
    for (int j=1;j<=5000;++j)
      if (f[i][j]!=inf){
	U(ans,(f[i][j]*1000+j-1)/j);
      }
  cout<<ans<<endl;
}