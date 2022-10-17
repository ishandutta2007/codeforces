#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,K=18;
int n,m,ans[N],pa[N];
bool in[N];
struct node{
  int u,v,w,id;
  bool operator < (const node &rhs) {
    return w<rhs.w;
  }
}e[N],E[N];
vector<int>g[N];
map<pair<int,int>,int>ids;
int fa[N],rev[N],sz[N],top[N],son[N],id[N],dep[N],p[N][K],dfn;
int get(int x){return x==pa[x]?x:pa[x]=get(pa[x]);}
void dfs1(int u){
  sz[u]=1;
  p[u][0]=fa[u];
  for(int i=1;i<K;++i){
    p[u][i]=p[p[u][i-1]][i-1];
  }
  for(auto v:g[u]){
    if(v!=fa[u]){
      fa[v]=u;
      dep[v]=dep[u]+1;
      dfs1(v);
      sz[u]+=sz[v];
      if(sz[son[u]]<sz[v]){
        son[u]=v;
      }
    }
  }
}
void dfs2(int u){
  id[u]=++dfn;      
  if(u!=1){
    rev[dfn]=ids[make_pair(u,fa[u])];
  }
  if(son[u]){
    top[son[u]]=top[u];
    dfs2(son[u]);
  }
  for(auto v:g[u]){
    if(v!=fa[u]&&v!=son[u]){
      top[v]=v;
      dfs2(v);
    }
  }
}
int jump(int u,int d){
  for(int i=K-1;~i;--i){
    if(dep[p[u][i]]>=d){
      u=p[u][i];
    } 
  }
  return u;
}
struct SegT{
  int val[N<<2];
  void build(int p,int l,int r){
    if(l==r){
      val[p]=E[rev[l]].w;
      return;
    }
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
    val[p]=max(val[p<<1],val[p<<1|1]);
  }  
  int query(int p,int l,int r,int ll,int rr) {
    if(l>=ll&&r<=rr){
      return val[p];
    }
    int mid=l+r>>1;
    if(mid>=ll&&mid<rr){
      return max(query(p<<1,l,mid,ll,rr),query(p<<1|1,mid+1,r,ll,rr));
    }else if(mid>=ll){
      return query(p<<1,l,mid,ll,rr);
    }else{
      return query(p<<1|1,mid+1,r,ll,rr);
    }
  }
  int query(int u,int v){
    int ans=0;
    while(top[u]!=top[v]){
      if(dep[top[u]]<dep[top[v]]){
        swap(u,v);
      }
      ans=max(ans,query(1,1,n,id[top[u]],id[u]));
      u=fa[top[u]];
    }
    if(u!=v){
      if(dep[u]>dep[v]){
        swap(u,v);
      } 
      ans=max(ans,query(1,1,n,id[jump(v,dep[u]+1)],id[v]));
    }
    return ans;
  }
}s1;
struct YetAnotherSegT{
  int tag[N<<2];
  void init(){fill(tag,tag+(N<<2),2e9);}
  void modify(int p,int l,int r,int ll,int rr,int v){
    if(l>=ll&&r<=rr){
      tag[p]=min(tag[p],v);
      return;
    }
    int mid=l+r>>1;
    if(mid>=ll){
      modify(p<<1,l,mid,ll,rr,v);
    }
    if(mid<rr){
      modify(p<<1|1,mid+1,r,ll,rr,v);
    }
  }
  void query(int p,int l,int r,int cur){
    cur=min(cur,tag[p]);
    if(l==r){
      ans[rev[l]]=cur==2e9?-1:cur;
      return;
    }
    int mid=l+r>>1;
    query(p<<1,l,mid,cur);
    query(p<<1|1,mid+1,r,cur);
  }
  void modify(int u,int v,int w){
    while(top[u]!=top[v]){
      if(dep[top[u]]<dep[top[v]]){
        swap(u,v);
      }
      modify(1,1,n,id[top[u]],id[u],w);
      u=fa[top[u]];
    }
    if(u!=v){
      if(dep[u]>dep[v]){
        swap(u,v);
      }
      modify(1,1,n,id[jump(v,dep[u]+1)],id[v],w);
    }
  }
}s2;
int main(){
  cin>>n>>m;
  for(int i=1;i<=m;++i){
    cin>>e[i].u>>e[i].v>>e[i].w;
    E[i]=e[i];
    int u=e[i].u,v=e[i].v;
    ids[make_pair(u,v)]=ids[make_pair(v,u)]=i;
    e[i].id=i;
  }
  sort(e+1,e+m+1);
  for(int i=1;i<=n;++i)pa[i]=i;
  for(int i=1;i<=m;++i){
    int u=e[i].u,v=e[i].v;
    int x=get(u),y=get(v);
    if(x!=y){
      pa[x]=y;
      in[e[i].id]=true;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
  }
  dfs1(1),top[1]=1,dfs2(1);
  s1.build(1,1,n),s2.init();
  for(int i=1;i<=m;++i){
    int u=E[i].u,v=E[i].v,w=E[i].w;
    if(!in[i]){
      ans[i]=s1.query(u,v)-1;
      s2.modify(u,v,w-1);
    }
  }
  s2.query(1,1,n,2e9);
  for(int i=1;i<=m;++i){
    cout<<ans[i]<<" \n"[i==m];
  }
}