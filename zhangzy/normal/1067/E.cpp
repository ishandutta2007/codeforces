#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 998244353

int n, f[505000], ans, iv2=mod+1>>1;
vector<int>G[505000];

void dfs(int x,int fff){
  f[x]=1;
  for (auto y:G[x])
    if (y!=fff){
      dfs(y,x);
      f[x]= (1-(ll)f[y]*iv2)%mod *f[x]%mod;
    }
  ans=(ans+1-f[x])%mod;
}

int main(){
  cin>>n;
  for (int i=n-1,u,v;i--;){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1,0);
  for (int i=1;i<=n;++i) ans=ans*2%mod;
  cout<<(ans+mod)%mod<<endl;
}