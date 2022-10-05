#pragma GCC target("arch=corei7-avx")
#include<bits/stdc++.h>
using namespace std;
#define rint register int
#define pic pair<int,char>
#define fi first
#define se second

int n, q, hea[22222], ui[22222], vi[22222]; char wi[22222], s[22222];
pic to[44444];
vector<int>ask[22222]; int ans[22222];
int fa[22222], dep[22222], st[22222], tp, f[22222]; char fc[22222];

int main(){
  cin>>n>>q;
  int u, v; char w;
  for (int i=1;i<n;++i){
    scanf("%d%d%s",&ui[i],&vi[i],s); wi[i]=s[0];
    u=ui[i]; v=vi[i]; w=wi[i];
    ++hea[u]; ++hea[v];
  }
  for (int i=1;i<=n+1;++i) hea[i]+=hea[i-1];
  for (int i=1;i<n;++i){
    u=ui[i]; v=vi[i]; w=wi[i];
    to[--hea[u]]=(pic){v,w};
    to[--hea[v]]=(pic){u,w};
  }
  for (int i=1;i<=n;++i) sort(to+hea[i],to+hea[i+1]);
  for (int i=1;i<=q;++i){
    scanf("%d%d",&ui[i],&vi[i]);
    ask[ui[i]].push_back(i);
  }
  for (int rt=1;rt<=n;++rt){
    if (!ask[rt].size()) continue;
    st[tp=1]=rt; fa[rt]=fc[rt]=dep[rt]=f[rt]=0;
    for (int it=1;it<=n;++it){
      rint x=st[it], y;
      for (int i=hea[x];i<hea[x+1];++i)
	if ((y=to[i].fi)!=fa[x]){
	  fa[y]=x; fc[y]=to[i].se; dep[y]=dep[x]+1;
	  st[++tp]=y;
	}
    }
    for (auto o:ask[rt]){
      v=vi[o]; int len=dep[v]; s[len+1]=0;
      for (;v!=rt;v=fa[v]) s[dep[v]]=fc[v];
      rint res=0, x;
      for (int it=2;it<=n;++it){
	x=st[it];
	if (f[fa[x]]){
	  f[x]= f[fa[x]]; res+= f[x]==1;
	}else{
	  f[x]= fc[x]>s[dep[x]]? -1: fc[x]<s[dep[x]];
	  res+= f[x]==1||f[x]==0&&dep[x]<len;
	}
      }
      ans[o]=res;
    }
  }
  for (int i=1;i<=q;++i) printf("%d\n",ans[i]);
}