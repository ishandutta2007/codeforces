#include<bits/stdc++.h>
#define fi first
using namespace std;

int n,m,k,fa[303000],fl[303000];
unordered_map<int,int>mp[303000];
map<int,int>las;
map<int,int>::iterator it,it2;

int GF(int x){ return x==fa[x]? x: fa[x]=GF(fa[x]); }

int main(){
  cin>>n>>m>>k;
  int x,y;
  for (int i=1;i<=m;++i){
    scanf("%d%d",&x,&y);
    mp[x][y]=mp[y][x]=1;
  }
  if (n-1-mp[1].size()<k) return 0*puts("impossible");
  for (int i=2;i<=n;++i) las[i]=1,fa[i]=i;
  for (int i=2;i<=n;++i){
    for (it=las.begin();it!=las.end();it=it2){
      it2=++it; --it;
      if (it->fi==i) continue;
      if (!mp[i].count(it->fi)){
	fa[GF(it->fi)]=GF(i);
	if (n>5000) las.erase(it);
      }
    }
  }
  int cnt=0;
  for (int i=2;i<=n;++i) if (!mp[1].count(i)) fl[GF(i)]=1;
  for (int i=2;i<=n;++i)
    if (fa[i]==i){
      if (!fl[i]) return 0*puts("impossible");
      ++cnt;
    }
  if (cnt>k) return 0*puts("impossible");
  puts("possible");
}