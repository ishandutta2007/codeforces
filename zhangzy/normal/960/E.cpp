#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n, sz[202000][2], a[202000];
vector<int>G[202000];
ll ans;

void add(int x,int y,int fl){
  sz[x][0]+=sz[y][1]*fl;
  sz[x][1]+=sz[y][0]*fl;
}

void dfs(int x,int fff){
  sz[x][0]=1; sz[x][1]=0;
  for (auto y:G[x])
    if (y!=fff)
      dfs(y,x), add(x,y,1);
}

void trans(int x,int y){
  add(y,x,-1);
  add(x,y,1);
}

void sfd(int x,int fff){
  for (auto y:G[x]){
    ll els=n-sz[y][0]-sz[y][1];
    ans+=sz[y][1]*els%mod*a[x]%mod;
    ans-=sz[y][0]*els%mod*a[x]%mod;
  }
  ans+=(ll)a[x]*n%mod;
  for (auto y:G[x])
    if (y!=fff){
      trans(y,x);
      sfd(y,x);
      trans(x,y);
    }
}

int main(){
  cin>>n;
  for (int i=1;i<=n;++i) scanf("%d",&a[i]);
  int u, v;
  for (int i=1;i<n;++i){
    scanf("%d%d",&u,&v);
    G[u].push_back(v); G[v].push_back(u);
  }
  dfs(1,0);
  sfd(1,0);
  ans=(ans%mod+mod)%mod;
  cout<<ans<<endl;
}