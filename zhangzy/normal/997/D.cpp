#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;


int n1, n2, k;
ll an1[88], an2[88];

ll sum[88];
namespace f__k{
  int n;
  vector<int>G[4040];
  ll f[4040][88], g[88];

  void cal(int x){
    memset(g,0,sizeof g); g[0]=1;
    for (int i=2;i<=k;i+=2)
      for (int j=0;j<i;j+=2)
	g[i]=(g[i]+g[j]*f[x][i-j])%mod;
  }
  
  void upd(int x,int y,int fl){
    cal(y);
    for (int i=2;i<=k;++i)
      if (g[i-2])
	f[x][i]=(f[x][i]+g[i-2]*fl+mod)%mod;
  }
  
  void dfs(int x,int fff){
    for (auto y:G[x])
      if (y!=fff)
	dfs(y,x), upd(x,y,1);
  }

  void trans(int x,int y){
    upd(x,y,-1);
    upd(y,x,1);
  }
  
  void sfd(int x,int fff){
    cal(x);
    //printf("%d::",x); for (int i=0;i<=k;++i) printf(" %lld",g[i]); puts("");
    for (int i=0;i<=k;++i) sum[i]=(sum[i]+g[i])%mod;
    for (auto y:G[x])
      if (y!=fff){
	trans(x,y);
	sfd(y,x);
	trans(y,x);
      }
  }
  
  void realmain(int n_){
    n=n_; memset(sum,0,sizeof sum);
    for (int i=1;i<=n;++i) G[i].clear();
    int x, y;
    for (int tim=n-1;tim--;){
      scanf("%d%d",&x,&y);
      G[x].push_back(y); G[y].push_back(x);
    }
    memset(f,0,sizeof f);
    dfs(1,0);
    sfd(1,0);
  }

}

ll c[88][88];

int main(){
  cin>>n1>>n2>>k;
  f__k::realmain(n1); memcpy(an1,sum,sizeof sum);
  f__k::realmain(n2); memcpy(an2,sum,sizeof sum);
  for (int i=0;i<=k;++i){
    c[i][0]=1;
    for (int j=1;j<=i;++j)
      c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
  }
  ll ans=0;
  for (int i=0;i<=k;++i)
    ans=(ans+an1[i]*an2[k-i]%mod*c[k][i])%mod;
  cout<<ans<<endl;
}