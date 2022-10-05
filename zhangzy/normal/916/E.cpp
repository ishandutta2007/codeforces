#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline void read(int &x){
  x=0; static bool fl; static char c;
  fl=0; c=getchar();
  for (;!(c<='9'&&c>='0');c=getchar()) if (c=='-') fl=1;
  for (; (c<='9'&&c>='0');c=getchar()) x=(x<<3)+(x<<1)+c-'0';
  if (fl) x=-x;
}

int n,T;

ll c[101000],s[101000],ans;
void A(int x,ll v,ll *c){ for (;x<=n;x+=x&-x) c[x]+=v; }
ll Q(int x,ll *c){ ll t=0; for (;x;x-=x&-x) t+=c[x]; return t; }
void AAA(int x,ll v){ A(x,v,c); A(x,v*x,s); }
ll QQQ(int x){ return Q(x,c)*(x+1)-Q(x,s); }
void add(int l,int r,ll v){ AAA(l,v); AAA(r+1,-v); }
ll que(int l,int r){ return QQQ(r)-QQQ(l-1); }

vector<int>G[101000];
int rt=1,a[101000],dep[101000],fa[101000],sz[101000],bs[101000];
int tp[101000],id[101000],tid=0,eid[101000];

void dfs(int x,int fff){
  dep[x]=dep[fa[x]=fff]+1;
  sz[x]=1;
  for (auto y:G[x])
    if (y!=fff){
      dfs(y,x); sz[x]+=sz[y];
      if (sz[y]>sz[bs[x]]) bs[x]=y;
    }
}

void pourshit(int x,int ttt){
  tp[x]=ttt; id[x]=++tid;
  if (bs[x]) pourshit(bs[x],ttt);
  for (auto y:G[x])
    if (y!=fa[x]&&y!=bs[x])
      pourshit(y,y);
  eid[x]=tid;
}

int lca(int x,int y){
  for (;tp[x]!=tp[y];){
    if (dep[tp[x]]<dep[tp[y]]) swap(x,y);
    x=fa[tp[x]];
  }
  return dep[x]>dep[y]? y: x;
}
int near(int x,int aim){
  for (;tp[x]!=tp[aim];){
    if (fa[tp[x]]==aim) return tp[x];
    x=fa[tp[x]];
  }
  return bs[aim];
}

#define all(x) id[x],eid[x]
int main(){
  read(n); read(T);
  for (int i=1;i<=n;++i) read(a[i]);
  int x,y,t,v;
  for (int i=1;i<n;++i){
    read(x); read(y);
    G[x].push_back(y); G[y].push_back(x);
  }
  dfs(1,0);
  pourshit(1,1);
  for (int i=1;i<=n;++i) add(id[i],id[i],a[i]);
  for (;T--;){
    read(t);
    if (t==1){
      read(rt);
    }else if (t==2){
      read(x); read(y); read(v);
      int l=lca(x,y), lx=lca(x,rt), ly=lca(y,rt), ne;
      if (dep[l]>dep[lx]&&dep[l]>dep[ly]){
	add(all(l),v); continue;
      }
      if (lx==rt||ly==rt){
	add(all(1),v); continue;
      }
      ne=near(rt, dep[lx]>dep[ly]? lx: ly);
      add(all(1),v); add(all(ne),-v);
    }else{
      read(x); int l=lca(x,rt),ne;
      if (l==x){
	ans=que(all(1));
	if (rt!=x) ne=near(rt,x), ans-=que(all(ne));
      }else{
	ans=que(all(x));
      }
      printf("%lld\n",ans);
    }
  }
}