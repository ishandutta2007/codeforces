//#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
vector<int>G[202000];
int n, sz[202000];
ll ans, cn[2];

void dfs(int x,int fff,int d){
  ++cn[d];
  sz[x]=1;
  for (auto y:G[x])
    if (y!=fff){
      dfs(y,x,d^1);
      sz[x]+=sz[y];
    }
  ans+=(ll)sz[x]*(n-sz[x]);
}

int main(){
  cin>>n;
  int x, y;
  for (int i=1;i<n;++i){
    scanf("%d%d",&x,&y);
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(1,0,0);
  ans+=(ll)cn[0]*cn[1];
  cerr<<ans<<endl;
  cout<<ans/2<<endl;
}