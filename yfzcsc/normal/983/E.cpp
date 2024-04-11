#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
struct wxh{int l,r,flg;};
vector<int>G[maxn],A[maxn];
vector<wxh>B[maxn];
int n,tim,dfn[maxn],mn,cnt[maxn],a[maxn],rig[maxn];
int son[maxn],fa[maxn],up[maxn],anses[maxn];
int nxt[maxn][20],m,Q,top[maxn],dep[maxn];
int dfs(int u,int f){
	int mxsize=0,s=0,sz=1;
	dep[u]=dep[f]+1,fa[u]=f;
//	printf("[%d]",u); 
	for(auto p:G[u])if(p!=f){
		s=dfs(p,u),sz+=s;
		if(mxsize<s)mxsize=s,son[u]=p;
	}
	return sz;
}
void dfs2(int u,int tp){
	a[dfn[u]=++tim]=u,top[u]=tp;
	if(son[u])dfs2(son[u],tp);
	for(auto p:G[u])if(p!=fa[u]&&p!=son[u])
		dfs2(p,p);
	rig[u]=tim;
}
void dfs3(int u){
	for(auto p:G[u])if(p!=fa[u]){
		dfs3(p);
		if(dep[up[u]]>dep[up[p]])up[u]=up[p];
	}
}
void dfs4(int u){
	nxt[u][0]=up[u];
//	printf("<%d,%d>",u,up[u]);
	for(int i=1;i<20;i++)
		nxt[u][i]=nxt[nxt[u][i-1]][i-1];
	for(auto p:G[u])if(p!=fa[u])dfs4(p);
}
int lca(int u,int v){
	while(top[u]!=top[v])
		dep[top[u]]>dep[top[v]]?u=fa[top[u]]:v=fa[top[v]];
	return dep[u]<dep[v]?u:v;
}
int tr[maxn];
void add(int x,int a){for(;x<=n;x+=x&-x)tr[x]+=a;}
int qry(int x){int ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}
int main(){
	scanf("%d",&n);
	for(int i=2,v;i<=n;++i){
		scanf("%d",&v);
		G[i].push_back(v);
		G[v].push_back(i);
	}
	dfs(1,0),dfs2(1,1);
	scanf("%d",&m);
	for(int i=1;i<=n;++i)up[i]=i; 
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		int lc=lca(u,v);
		if(dep[up[u]]>dep[lc])up[u]=lc;
		if(dep[up[v]]>dep[lc])up[v]=lc;
//		printf("{%d}",lc);
		if(dfn[u]>dfn[v])swap(u,v);
		A[dfn[u]].push_back(dfn[v]);
	}
	dfs3(1),dfs4(1);
	scanf("%d",&Q);
	for(int i=1,u,v;i<=Q;++i){
		scanf("%d%d",&u,&v);
		if(dfn[u]>dfn[v])swap(u,v);
		int lc=lca(u,v);
		int fu=u,fv=v,a=0,b=0;
		for(int i=19;i>=0;--i)if(dep[nxt[u][i]]>dep[lc])
			u=nxt[u][i],a+=1<<i;
		for(int i=19;i>=0;--i)if(dep[nxt[v][i]]>dep[lc])
			v=nxt[v][i],b+=1<<i;
		if(dep[nxt[u][0]]>dep[lc]||dep[nxt[v][0]]>dep[lc]){anses[i]=-1;continue;}
		if(lc==fu){anses[i]=b+1;continue;}
		anses[i]=a+b+2;
//		printf("<%d,%d,%d>",anses[i],a,b);
		B[dfn[u]-1].push_back(wxh{dfn[v],rig[v],-i});
		B[rig[u]].push_back(wxh{dfn[v],rig[v],i});
	}
	for(int i=1;i<=n;++i){
		for(auto p:A[i])add(p,1);
		for(auto p:B[i])
			cnt[abs(p.flg)]+=(qry(p.r)-qry(p.l-1))*(p.flg>0?1:-1);
	}
	for(int i=1;i<=Q;++i){
		if(cnt[i])anses[i]--;
		printf("%d\n",anses[i]);
	}
}