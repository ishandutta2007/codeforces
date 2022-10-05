#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 202000

int n,c[N],sz[N],die[N],cnt[1101000];
vector<int>G[N];
char s[N];
ll ans[N];

void getsz(int x,int fff){
  sz[x]=1;
  for (auto y:G[x])
    if (y-fff&&!die[y])
      getsz(y,x), sz[x]+=sz[y];
}

int getrt(int x,int fff,int tot){
  for (auto y:G[x])
    if (y-fff&&!die[y]&&sz[y]*2>=tot)
      return getrt(y,x,tot);
  return x;
}

void dfs(int x,int fff,int now,int fl){
  cnt[now^=1<<c[x]]+=fl;
  for (auto y:G[x])
    if (y-fff&&!die[y])
      dfs(y,x,now,fl);
}

ll D(int x,int fff,int now){
  now^=1<<c[x];
  ll res=cnt[now];
  for (int i=0;i<20;++i) res+=cnt[now^(1<<i)];
  for (auto y:G[x])
    if (y-fff&&!die[y]){
      res+=D(y,x,now);
    }
  ans[x]+=res;
  return res;
}

void doit(int x){
  die[x]=1;
  dfs(x,0,0,1);
  ll res=0;
  for (auto y:G[x]) if (!die[y]){
      dfs(y,x,1<<c[x],-1);
      res+=D(y,x,0);
      dfs(y,x,1<<c[x],1);
    }
  for (int i=0;i<20;++i) res+=cnt[1<<i];
  res+=cnt[0]-1;
  ans[x]+=res/2+1;
  dfs(x,0,0,-1);
  for (auto y:G[x]) if (!die[y]){
      getsz(y,x);
      doit(getrt(y,x,sz[y]));
    }
}

int main(){
  ios::sync_with_stdio(false);
  cin>>n; int x,y;
  for (int i=n;--i;) cin>>x>>y, G[x].push_back(y), G[y].push_back(x);
  cin>>s+1; for (int i=1;i<=n;++i) c[i]=s[i]-'a';
  getsz(1,0);
  doit(getrt(1,0,sz[1]));
  for (int i=1;i<=n;++i) cout<<ans[i]<<' ';
}