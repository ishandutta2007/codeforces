#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int k, n, m;
vector <pair <int, int>> a[2];
vector <int> v;
const int base=1000000007;
int e[400010][2];
ll f[400010][3];
ll g[400010][3];
ll power(ll a, int b){
  if(b==0) return 1;
  ll t=power(a, b/2);
  t=(t*t)%base;
  if(b%2) t=(t*a)%base;
  return t;
}
int main(){
  cin>>k>>n>>m;
  a[0].resize(n);
  for(auto &x: a[0]){
    cin>>x.first>>x.second;
    v.push_back(x.first-1);
    v.push_back(x.second);
  }
  a[1].resize(m);
  for(auto &x: a[1]){
    cin>>x.first>>x.second;
    v.push_back(x.first-1);
    v.push_back(x.second);
  }
  v.push_back(0);
  v.push_back(k);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  f[0][2]=1;
  g[0][2]=1;
  for(int b=0; b<=1; b++){
    for(auto &x: a[b]){
      x.first=lower_bound(v.begin(), v.end(), x.first-1)-v.begin()+1;
      x.second=lower_bound(v.begin(), v.end(), x.second)-v.begin();
      e[x.second][b]=max(e[x.second][b], x.first);
    }
    for(int i=1; i<v.size(); i++) e[i][b]=max(e[i][b], e[i-1][b]);
  }
  ll ans=1;
  for(int i=1; i<v.size(); i++){
    ll c=(power(2, v[i]-v[i-1])+base-2)%base;
    f[i][2]=((f[i-1][0]+f[i-1][1]+f[i-1][2])*c)%base;
    if(e[i][1]==0) f[i][0]=(g[i-1][1]+g[i-1][2])%base;
    else f[i][0]=((g[i-1][1]-g[e[i][1]-1][1])+(g[i-1][2]-g[e[i][1]-1][2]))%base;
    if(e[i][0]==0) f[i][1]=(g[i-1][0]+g[i-1][2])%base;
    else f[i][1]=((g[i-1][0]-g[e[i][0]-1][0])+(g[i-1][2]-g[e[i][0]-1][2]))%base;
    g[i][0]=(g[i-1][0]+f[i][0])%base;
    g[i][1]=(g[i-1][1]+f[i][1])%base;
    g[i][2]=(g[i-1][2]+f[i][2])%base;
    ans=f[i][0]+f[i][1]+f[i][2];
  }
  ans%=base;
  ans=(ans+base)%base;
  cout<<ans<<'\n';
}