#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n,m,a[310],f[101000],to[310],fl[310],used[310];
ll k,tot,d;
vector<int>vec;

int dfs(int x,ll tot,ll &dep){
  used[x]=1; tot+=a[x];
  if (!to[x]) dep=0;
  else{
    dfs(to[x],tot,dep);
    ++dep;
  }
  k-=dep*a[x]; if (k<0) exit(0*puts("0"));
  vec.push_back(tot);
}

int main(){
  cin>>n>>m>>k;
  for (int i=1;i<=n;++i) cin>>a[i];
  int x,y;
  for (;m--;){
    cin>>x>>y;
    to[x]=y; fl[y]=1;
  }
  for (int i=1;i<=n;++i) if (!fl[i]){
      dfs(i,0,d);
    }
  for (int i=1;i<=n;++i) if (!used[i]) exit(0*puts("0"));
  memset(f,0,sizeof f); f[0]=1; cerr<<k<<endl;
  for (auto o:vec){
    for (int i=o;i<=k;++i) f[i]=(f[i]+f[i-o])%mod;
  }
  cout<<f[k]<<endl;
}