#include<bits/stdc++.h>
#define rint register int
using namespace std;

int n, mx[(1<<22)+233];
vector<int>G[505000];
int df1[505000], df2[505000], dft, bs[505000];
int val[505000], dep[505000], dfv[505000], dfd[505000];
int ans[505000];

void pre(int x){
  df1[x]=++dft;
  dfv[dft]=val[x]; dfd[dft]=dep[x];
  for (auto y:G[x]){
    pre(y);
    if (!bs[x]||df2[y]-df1[y]>df2[bs[x]]-df1[bs[x]])
      bs[x]=y;
  }
  df2[x]=dft;
}

void del(int l,int r){
  for (rint i=l;i<=r;++i) mx[dfv[i]]=-1;
}

void add(int l,int r,int lca){
  int tmp;
  for (int i=l;i<=r;++i){
    for (rint j=0;j<22;++j)
      if (~(tmp=mx[dfv[i]^1<<j]))
	ans[lca]=max(ans[lca],tmp+dfd[i]-dep[lca]*2);
    if (~(tmp=mx[dfv[i]]))
      ans[lca]=max(ans[lca],tmp+dfd[i]-dep[lca]*2);
  }
  for (rint i=l;i<=r;++i)
    mx[dfv[i]]=max(mx[dfv[i]],dfd[i]);
}

void dfs(int x){
  for (auto y:G[x])
    if (y!=bs[x]){
      dfs(y);
      del(df1[y],df2[y]);
    }
  if (bs[x]) dfs(bs[x]);
  add(df1[x],df1[x],x);
  for (auto y:G[x])
    if (y!=bs[x]){
      add(df1[y],df2[y],x);
    }
  for (auto y:G[x])
    ans[x]=max(ans[x],ans[y]);
}

int main(){
  cin>>n;
  int fa; char c;
  for (int i=2;i<=n;++i){
    scanf("%d",&fa); getchar(); c=getchar();
    val[i]=val[fa]^(1<<(c-'a'));
    dep[i]=dep[fa]+1;
    G[fa].push_back(i);
  }
  pre(1);
  memset(mx,-1,sizeof mx);
  dfs(1);
  for (int i=1;i<=n;++i) printf("%d ",ans[i]);
}