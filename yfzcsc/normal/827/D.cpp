#include<bits/stdc++.h>
#define maxn 300100
using namespace std;
const int inf=1000000007;
const int safe=1000000001;
struct edge{int r,nxt,w,bh;}e[maxn<<1];
struct data{int u,v,w,bh;int operator<(const data& d)const{return w<d.w;}}d[maxn];
int n,m,head[maxn],son[maxn],f[maxn],a,esz,anses[maxn];
int dep[maxn],top[maxn],fa[maxn],tim,id[maxn],dfn[maxn],pre[maxn];
int mx[maxn<<2],tg[maxn<<2],vis[maxn];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
void addedge(int u,int v,int w,int bh){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;e[esz].bh=bh;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=w;e[esz].bh=bh;
}
int dfs(int u){
	int sz=1,mxsize=0,s;
	dep[u]=dep[fa[u]]+1;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]){
		fa[e[t].r]=u,pre[e[t].r]=e[t].bh,s=dfs(e[t].r),sz+=s;
		if(mxsize<s)mxsize=s,son[u]=e[t].r;
	}
	return sz;
}
void dfs2(int u,int tp){
	top[u]=tp,dfn[id[u]=++tim]=u;
	if(son[u])dfs2(son[u],tp);
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]&&e[t].r!=son[u])
		dfs2(e[t].r,e[t].r);
}
void build(int o,int l,int r){
	tg[o]=inf,mx[o]=-inf;
	if(l==r){
		mx[o]=d[pre[dfn[l]]].w;
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void mdy(int o,int l,int r,int ql,int qr,int c){
	if(ql<=l&&r<=qr){
		tg[o]=min(tg[o],c);
		return ;
	}
	int mid=l+r>>1;
	if(ql<=mid)mdy(o<<1,l,mid,ql,qr,c);
	if(qr>mid)mdy(o<<1|1,mid+1,r,ql,qr,c);
}
int qry(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return mx[o];
	int mid=l+r>>1;
	if(qr<=mid)return qry(o<<1,l,mid,ql,qr);
	else if(ql>mid)return qry(o<<1|1,mid+1,r,ql,qr);
	else return max(qry(o<<1,l,mid,ql,qr),qry(o<<1|1,mid+1,r,ql,qr));
}
int qtree(int u,int v,int cs){
	int ans=-inf;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		ans=max(ans,qry(1,1,n,id[top[u]],id[u]));
		mdy(1,1,n,id[top[u]],id[u],cs);
		u=fa[top[u]];
	}
	if(u==v)return ans-1;
	if(dep[u]>dep[v])swap(u,v);
	ans=max(ans,qry(1,1,n,id[son[u]],id[v]));
	mdy(1,1,n,id[son[u]],id[v],cs);
	return ans-1;
}
void print(int o,int l,int r,int x){
	x=min(x,tg[o]);
	
	if(l==r){
	//	printf("[%d]",x);
		anses[d[pre[dfn[l]]].bh]=x-1;
		return ;
	}
	int mid=l+r>>1;
	print(o<<1,l,mid,x);
	print(o<<1|1,mid+1,r,x);
}
int main(){
//	freopen("weight1.in","r",stdin);
//	freopen("weight1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&d[i].u,&d[i].v,&d[i].w),d[i].bh=i;
	sort(d+1,d+m+1);
	for(int i=1;i<=n;++i)f[i]=i;
	for(int i=1;i<=m;++i){
		int u=d[i].u,v=d[i].v;
		u=find(u),v=find(v);
		if(u==v)continue;
		vis[i]=1;
		addedge(d[i].u,d[i].v,d[i].w,i);
		f[find(u)]=find(v);
	}
	dfs(1),dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;++i)if(!vis[i])
		anses[d[i].bh]=qtree(d[i].u,d[i].v,d[i].w);//,printf("[bh=%d(%d,%d)]",d[i].bh,anses[d[i].bh],d[i].w);
	print(1,1,n,inf);
	for(int i=1;i<=m;++i)printf("%d ",anses[i]>=safe?-1:anses[i]);
}