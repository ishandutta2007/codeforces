#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n,m;
char s[2020];
ll f[2020][2020],ans,g[2020];

void U(ll &x,ll y){
  x=(x+y)%mod;
}

int main(){
  cin>>n>>m>>s+1;
  f[0][0]=1; g[0]=1;
  for (int i=1;i<=n;++i){
    for (int j=0;j<=m;++j){
      U(f[i][j],g[j]*(s[i]-'a'));
      for (int k=i-1;~k&&j+(i-k)*(n+1-i)<=m;--k)
	U(f[i][j+(i-k)*(n+1-i)],f[k][j]*('z'-s[i]));
      U(g[j],f[i][j]);
    }
  }
  cout<<g[m]<<endl;
}