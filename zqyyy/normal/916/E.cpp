#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int N=3e5+5;
struct Query{int op,u,v,x;}q[N];
struct Segment_Tree{
	ll t[N<<2],tg[N<<2];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void spread(int p,int l,int r){
		if(!tg[p])return;int mid=(l+r)>>1;
		t[ls]+=tg[p]*(mid-l+1),t[rs]+=tg[p]*(r-mid);
		tg[ls]+=tg[p],tg[rs]+=tg[p];
		tg[p]=0;
	}
	void modify(int p,int l,int r,int x,int y,int val){
		if(x<=l && r<=y){t[p]+=1ll*val*(r-l+1),tg[p]+=val;return;}
		spread(p,l,r);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,val);
		if(y>mid)modify(rs,mid+1,r,x,y,val);
		t[p]=t[ls]+t[rs];
	}
	ll query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return t[p];
		spread(p,l,r);int mid=(l+r)>>1;ll ans=0;
		if(x<=mid)ans+=query(ls,l,mid,x,y);
		if(y>mid)ans+=query(rs,mid+1,r,x,y);
		return ans;
	}
}T;
int n,rt,Q;
ll w[N],ans;
vector<int>G[N];
int tot,f[N][19],dfn[N],ed[N],dep[N];
void dfs(int x,int fa){
	f[x][0]=fa,dfn[x]=++tot,dep[x]=dep[fa]+1;
	for(int i=1;i<=18;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:G[x])if(y^fa)dfs(y,x);
	ed[x]=tot;
}
inline int LCA(int x,int y){
	if(x==y)return y;if(dfn[x]>dfn[y])swap(x,y);
	for(int i=18;~i;i--)
		if(dfn[f[y][i]]>dfn[x])y=f[y][i];
	return f[y][0];
}
inline int Get_son(int x,int y){
	for(int i=18;~i;i--)
		if(dep[f[y][i]]>dep[x])y=f[y][i];
	return y;
}
int main(){
	n=read(),Q=read(),rt=1;
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for(int i=1;i<=Q;i++){
		q[i].op=read();
		if(q[i].op==1)q[i].x=read();
		else if(q[i].op==2)q[i].u=read(),q[i].v=read(),q[i].x=read();
		else q[i].x=read();
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)T.modify(1,1,n,dfn[i],dfn[i],w[i]);
	for(int i=1;i<=n;i++)ans+=w[i];
	for(int i=1;i<=Q;i++){
		if(q[i].op==1)rt=q[i].x;
		else if(q[i].op==2){
			int x=q[i].u,y=q[i].v;
			if(dfn[rt]<=dfn[y] && dfn[y]<=ed[rt])swap(x,y);
			if(dfn[rt]<=dfn[x] && dfn[x]<=ed[rt]){
				if(dfn[rt]>dfn[y] || ed[rt]<dfn[y])T.modify(1,1,n,1,n,q[i].x),ans+=1ll*n*q[i].x;
				else{
					int lca=LCA(x,y);
					if(lca==rt)T.modify(1,1,n,1,n,q[i].x),ans+=1ll*n*q[i].x;
					else T.modify(1,1,n,dfn[lca],ed[lca],q[i].x),ans+=1ll*q[i].x*(ed[lca]-dfn[lca]+1);
				}
			}else{
				int lca=LCA(x,y);
				if(dfn[lca]<=dfn[rt] && dfn[rt]<=dfn[lca]){
					int z=Get_son(lca,rt);
					if(dfn[z]^1)T.modify(1,1,n,1,dfn[z]-1,q[i].x),ans+=1ll*q[i].x*(dfn[z]-1);
					if(ed[z]^n)T.modify(1,1,n,ed[z]+1,n,q[i].x),ans+=1ll*q[i].x*(n-ed[z]);
				}else{
					int k1=LCA(rt,x),k2=LCA(rt,y),k=dep[k1]>dep[k2]?k1:k2;
					if(dep[k]>=dep[lca]){
						int z=Get_son(k,rt);
						if(dfn[z]^1)T.modify(1,1,n,1,dfn[z]-1,q[i].x),ans+=1ll*q[i].x*(dfn[z]-1);
						if(ed[z]^n)T.modify(1,1,n,ed[z]+1,n,q[i].x),ans+=1ll*q[i].x*(n-ed[z]);
					}else T.modify(1,1,n,dfn[lca],ed[lca],q[i].x),ans+=1ll*q[i].x*(ed[lca]-dfn[lca]+1);
				}
			}
		}else{
			if(rt==q[i].x)printf("%lld\n",ans);
			else{
				int lca=LCA(rt,q[i].x);
				if(lca==q[i].x){
					int y=Get_son(lca,rt);
					printf("%lld\n",ans-T.query(1,1,n,dfn[y],ed[y]));
				}
				else printf("%lld\n",T.query(1,1,n,dfn[q[i].x],ed[q[i].x]));
			}
		}
	}
	return 0;
}