#pragma GCC target("arch=corei7-avx")
#include<bits/stdc++.h>
using namespace std;

int n, m, fa[22222][15], dep[22222];
vector<int>G[22222];

struct E{
  int to, nex, fl;
}e[4004000];
int s, t, hea[402000], cur[402000], cne=1, inf=1e7, d[402000];

map<int,int>eid[22222];
int ie[22222], iv[22222];

bool BB(){
  queue<int>q;
  memset(d,33,sizeof d); d[s]=0;
  for (q.push(s);!q.empty();q.pop()){
    int x=q.front(); if (x==t) return 1;
    for (int i=hea[x];i;i=e[i].nex){
      int y=e[i].to; if (!e[i].fl) continue;
      if (d[y]>inf) d[y]=d[x]+1, q.push(y);
    }
  }
  return 0;
}
int DD(int x,int F){
  if (!F||x==t) return F;
  int las=F;
  for (int &i=cur[x];i;i=e[i].nex){
    int y=e[i].to; if (!e[i].fl||d[y]!=d[x]+1) continue;
    int t=DD(y,min(las,e[i].fl));
    if (t){
      e[i].fl-=t; e[i^1].fl+=t;
      if (!(las-=t)) return F;
    }
  }
  return F-las;
}
int dinic(){
  int res=0;
  for (;BB();) memcpy(cur,hea,sizeof hea), res+=DD(s,inf);
  return res;
}

int ID(int x,int y){
  return x*15+y+23333;
}
void add(int u,int v,int w){
  e[++cne]=(E){v,hea[u],w}; hea[u]=cne;
  e[++cne]=(E){u,hea[v],0}; hea[v]=cne;
}

void dfs(int x,int fff){
  fa[x][0]=fff; dep[x]=dep[fff]+1;
  add(ID(x,0),t,1); ie[eid[x][fff]]=ID(x,0);
  for (int i=1;i<=14;++i){
    fa[x][i]=fa[fa[x][i-1]][i-1];
    add(ID(x,i),ID(x,i-1),inf);
    add(ID(x,i),ID(fa[x][i-1],i-1),inf);
  }
  for (auto y:G[x])
    if (y!=fff) dfs(y,x);
}

int main(){
  cin>>n>>m; s=m+1; t=m+2;
  int u, v;
  for (int i=1;i<n;++i){
    cin>>u>>v; eid[u][v]=eid[v][u]=i;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1,0);
  for (int c=1;c<=m;++c){
    cin>>u>>v;
    add(s,c,1); iv[c]=c;
    #define lover(u,i) add(c,ID(u,i),inf), u=fa[u][i]
    if (dep[u]<dep[v]) swap(u,v);
    for (int i=14;i>=0;--i)
      if (dep[fa[u][i]]>=dep[v])
	lover(u,i);
    if (u==v) continue;
    for (int i=14;i>=0;--i)
      if (fa[u][i]!=fa[v][i])
	lover(u,i), lover(v,i);
    lover(u,0); lover(v,0);
  }
  cout<<dinic()<<endl;
  vector<int>a, b;
  for (int i=1;i<=2e4;++i){
    if (i<=m&&d[iv[i]]>inf) a.push_back(i); 
    if (i<=n&&d[ie[i]]<inf) b.push_back(i);
  }
  cout<<a.size(); for (auto o:a) printf(" %d",o); puts("");
  cout<<b.size(); for (auto o:b) printf(" %d",o); puts("");
}