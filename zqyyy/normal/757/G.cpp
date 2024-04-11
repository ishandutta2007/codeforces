#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=2e5+7;
struct Edge{int to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
    e[++s_e]={y,head[x],w},head[x]=s_e;
}
int n,Q,p[N];
int s_dfn,fa[N],sz[N],son[N],top[N],dfn[N],id[N];
ll d[N],sum[N],s[N];
void dfs1(int x,int pa){
    sz[x]=1,fa[x]=pa;
    for(int i=head[x];i;i=e[i].nxt){
	int y=e[i].to;if(y==pa)continue;
	d[y]=d[x]+e[i].w,dfs1(y,x),sz[x]+=sz[y];
	if(sz[y]>sz[son[x]])son[x]=y;
    }
}
void dfs2(int x,int tf){
    top[x]=tf,dfn[x]=++s_dfn,id[s_dfn]=x;if(!son[x])return;dfs2(son[x],tf);
    for(int i=head[x],y;i;i=e[i].nxt)if((y=e[i].to)!=fa[x] && y!=son[x])dfs2(y,y);
}
const int M=3e7;
int now,rt[N];
struct hjt{
    ll t[M],tt[M];int tot,ls[M],rs[M];
    void modify(int &p,int q,int l,int r,int x,int y){
	if(p<=now)p=++tot,ls[p]=ls[q],rs[p]=rs[q],t[p]=t[q],tt[p]=tt[q];
	if(x<=l && r<=y){t[p]++;return;}
	tt[p]+=s[y]-s[x-1];int mid=(l+r)>>1;
	if(y<=mid)modify(ls[p],ls[q],l,mid,x,y);
	else if(x>mid)modify(rs[p],rs[q],mid+1,r,x,y);
	else modify(ls[p],ls[q],l,mid,x,mid),modify(rs[p],rs[q],mid+1,r,mid+1,y);
    }
    ll query(int p,int q,int l,int r,int x,int y){
	if(!p && !q)return 0;
	ll res=(s[y]-s[x-1])*(t[p]-t[q]);
	if(x<=l && r<=y)return res+tt[p]-tt[q];
	int mid=(l+r)>>1;
	if(y<=mid)return res+query(ls[p],ls[q],l,mid,x,y);
	if(x>mid)return res+query(rs[p],rs[q],mid+1,r,x,y);
	return res+query(ls[p],ls[q],l,mid,x,mid)+query(rs[p],rs[q],mid+1,r,mid+1,y);
    }
}T;
inline void modify(int i,int x){
    now=T.tot,rt[i]=0;
    while(x){
      	T.modify(rt[i],rt[i-1],1,n,dfn[top[x]],dfn[x]);
	x=fa[top[x]];
    }
}
inline ll query(int l,int r,int x){
    ll res=(r-l+1)*d[x]+sum[r]-sum[l-1];
    while(x){
	res-=T.query(rt[r],rt[l-1],1,n,dfn[top[x]],dfn[x])<<1;
	x=fa[top[x]];
    }
    return res;
}
const int mod=1<<30;
int main(){
    n=read(),Q=read();
    for(int i=1;i<=n;i++)p[i]=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read(),w=read();
	add_e(x,y,w),add_e(y,x,w);
    }
    dfs1(1,0),dfs2(1,1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+d[id[i]]-d[fa[id[i]]],sum[i]=sum[i-1]+d[p[i]];
    for(int i=1;i<=n;i++)modify(i,p[i]);
    ll ans=0;
    while(Q--){
	int opt=read();
	if(opt==1){
	    int l=ans^read(),r=ans^read(),x=ans^read();
	    printf("%lld\n",ans=query(l,r,x)),ans%=mod;
	}else{
	    int x=ans^read();
	    sum[x]=sum[x-1]+d[p[x+1]];
	    if(T.tot+1e6>M){
		swap(p[x],p[x+1]),T.tot=0;
		for(int i=1;i<=n;i++)modify(i,p[i]);
	    }else modify(x,p[x+1]),swap(p[x],p[x+1]);
	}
    }
    return 0;
}