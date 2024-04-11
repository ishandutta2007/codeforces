#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
inline char getc(){
	char c;
	while(!isalpha(c=getchar()));
	return c;
}
const int N=2e5+7;
int n,m,Q,w[N];
namespace Tree{
	vector<int>G[N];
	inline void add_e(int x,int y){
		G[x].push_back(y),G[y].push_back(x);
	}
	int n,s_dfn,dfn[N],id[N],sz[N],son[N],dep[N],fa[N],top[N];
	void dfs1(int x,int f){
		fa[x]=f,sz[x]=1,dep[x]=dep[f]+1;
		for(int y:G[x])
			if(y^f){
				dfs1(y,x),sz[x]+=sz[y];
				if(sz[y]>sz[son[x]])son[x]=y;
			}
	}
	void dfs2(int x,int tf){
		top[x]=tf,dfn[x]=++s_dfn,id[s_dfn]=x;
		if(!son[x])return;dfs2(son[x],tf);
		for(int y:G[x])
			if(y!=fa[x] && y!=son[x])dfs2(y,y);
	}
	struct Segment_Tree{
		int t[N<<2];
#define ls (p<<1)
#define rs (p<<1|1)
		inline void upd(int p){t[p]=min(t[ls],t[rs]);}
		void build(int p,int l,int r){
			if(l==r){t[p]=w[id[l]];return;}
			int mid=(l+r)>>1;build(ls,l,mid),build(rs,mid+1,r),upd(p);
		}
		void modify(int p,int l,int r,int x,int v){
			if(l==r){t[p]=v;return;}
			int mid=(l+r)>>1;
			if(x<=mid)modify(ls,l,mid,x,v);
			else modify(rs,mid+1,r,x,v);
			upd(p);
		}
		int query(int p,int l,int r,int x,int y){
			if(x<=l && r<=y)return t[p];
			int mid=(l+r)>>1;
			if(y<=mid)return query(ls,l,mid,x,y);
			if(x>mid)return query(rs,mid+1,r,x,y);
			return min(query(ls,l,mid,x,y),query(rs,mid+1,r,x,y));
		}
	}T;
	inline void modify(int x,int v){T.modify(1,1,n,dfn[x],v);}
	inline int query(int x,int y){
		int ans=0x3f3f3f3f;
		while(top[x]^top[y]){
			if(dep[top[x]]>dep[top[y]])swap(x,y);
			ans=min(ans,T.query(1,1,n,dfn[top[y]],dfn[y])),y=fa[top[y]];
		}
		if(dfn[x]>dfn[y])swap(x,y);
		ans=min(ans,T.query(1,1,n,dfn[x],dfn[y]));
		if(x>::n)ans=min(ans,w[fa[x]]);
		return ans;
	}
	inline void init(){
		dfs1(1,0),dfs2(1,1),T.build(1,1,n);
	}
}
namespace Graph{
	vector<int>G[N];
	int s_dfn,tot,col[N],dfn[N],low[N],tp,stk[N];
	multiset<int>s[N];
	void tarjan(int x,int in){
		dfn[x]=low[x]=++s_dfn,stk[++tp]=x;
		for(int y:G[x]){
			if(y==in)continue;
			if(!dfn[y]){
				tarjan(y,x),low[x]=min(low[x],low[y]);
				if(low[y]>=dfn[x]){
					tot++;int z;
					do{
						z=stk[tp--];
						Tree::add_e(tot,z);
						col[z]=tot;
					}while(z!=y);
					Tree::add_e(tot,x);
				}
			}else low[x]=min(low[x],dfn[y]);
		}
	}
	inline void init(){
		for(int i=1,x,y;i<=m;i++)
			x=read(),y=read(),G[x].push_back(y),G[y].push_back(x);
		tot=n,tarjan(1,0),Tree::n=tot;
		for(int i=1;i<=n;i++)
			if(col[i])s[col[i]].insert(w[i]);
		for(int i=n+1;i<=tot;i++)w[i]=*s[i].begin();
		Tree::init();
	}
	inline void modify(int x,int v){
		if(col[x]){
			int u=col[x];
			s[u].erase(s[u].find(w[x]));
			s[u].insert(v),Tree::modify(u,w[u]=*s[u].begin());
		}
		Tree::modify(x,w[x]=v);
	}
	inline int query(int x,int y){
		return Tree::query(x,y);
	}
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;i++)w[i]=read();
	Graph::init();
	while(Q--){
		char opt=getc();
		if(opt=='C'){
			int x=read(),v=read();
			Graph::modify(x,v);
		}else printf("%d\n",Graph::query(read(),read()));
	}
	return 0;
}