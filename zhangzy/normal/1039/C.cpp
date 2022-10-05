#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int n, m, k, fa[505000]; ll a[505000], pw[505000]={1};
#define pii pair<int,int>
#define fi first
#define se second
map<ll,vector<pii> >mp;

int GF(int x){
  return x==fa[x]? x: fa[x]=GF(fa[x]);
}

int main(){
  cin>>n>>m>>k;
  for (int i=1;i<=n;++i)
    scanf("%lld",&a[i]), fa[i]=i, pw[i]=pw[i-1]*2%mod;
  for (int i=n+1;i<=k;++i) pw[i]=pw[i-1]*2%mod;
  int u, v;
  for (int i=1;i<=m;++i){
    scanf("%d%d",&u,&v);
    mp[a[u]^a[v]].push_back((pii){u,v});
  }
  ll ans=pw[k]*pw[n];
  for (auto &it:mp){
    int c=n;
    for (auto &e:it.se){
      u=GF(e.fi); v=GF(e.se);
      if (u!=v) --c, fa[u]=v;
    }
    ans+=pw[c]-pw[n];
    for (auto &e:it.se){
      u=e.fi; v=e.se;
      fa[u]=u; fa[v]=v;
    }
  }
  cout<<(ans%mod+mod)%mod<<endl;
}