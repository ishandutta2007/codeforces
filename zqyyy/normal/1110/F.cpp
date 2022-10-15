#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
#define mk make_pair
const int N=5e5+7;
const ll INF=1e18;
struct Segment_Tree{
	ll t[N<<2],tg[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
	inline void spread(int p){
		if(!tg[p])return;
		t[ls]+=tg[p],t[rs]+=tg[p];
		tg[ls]+=tg[p],tg[rs]+=tg[p],tg[p]=0;
	}
	void modify(int p,int l,int r,int x,int y,ll val){
		if(x<=l && r<=y){t[p]+=val,tg[p]+=val;return;}
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,val);
		if(y>mid)modify(rs,mid+1,r,x,y,val);
		t[p]=min(t[ls],t[rs]);
	}
	ll query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];
		spread(p);int mid=(l+r)>>1;ll res=INF;
		if(x<=mid)res=min(res,query(ls,l,mid,x,y));
		if(y>mid)res=min(res,query(rs,mid+1,r,x,y));
		return res;
	}
}T;
struct Edge{int to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
	e[++s_e]=(Edge){y,head[x],w},head[x]=s_e;
}
int n,m,fa[N],w[N],sz[N];
ll ans[N],dis[N];
vector<pair<pii,int> >q[N];
bool is_leaf[N];
void dfs(int x){
	for(auto i:q[x]){
		int id=i.se,l=i.fi.fi,r=i.fi.se;
		ans[id]=T.query(1,1,n,l,r);
	}
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		T.modify(1,1,n,1,n,e[i].w),T.modify(1,1,n,y,y+sz[y]-1,-(e[i].w<<1)),dfs(y);
		T.modify(1,1,n,1,n,-e[i].w),T.modify(1,1,n,y,y+sz[y]-1,e[i].w<<1);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)is_leaf[i]=1,sz[i]=1;
	for(int i=2,val;i<=n;i++){
		fa[i]=read(),w[i]=read();
		dis[i]=dis[fa[i]]+w[i],is_leaf[fa[i]]=0;
	}
	for(int i=n;i>1;i--)add_e(fa[i],i,w[i]),sz[fa[i]]+=sz[i];
	for(int i=1;i<=m;i++){
		int x=read(),l=read(),r=read();
		q[x].push_back(mk(mk(l,r),i));
	}
	for(int i=1;i<=n;i++)
		if(is_leaf[i])T.modify(1,1,n,i,i,dis[i]);
		else T.modify(1,1,n,i,i,INF);
	dfs(1);
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}