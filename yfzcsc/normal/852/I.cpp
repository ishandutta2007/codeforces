#include<bits/stdc++.h>
#define maxn 200100
using namespace std;
struct edge{int r,nxt;}e[maxn<<1];
struct query{int l,r,bh,kl;}q[maxn];
int head[maxn],esz,n,dep[maxn],a[maxn],fa[maxn][20],sz,tp;
int f[maxn],g[maxn],tg[maxn],lsh[maxn];
int kuai,isboy[maxn],num[maxn],m,boys[maxn],girls[maxn];
bool vis[maxn];
long long ans=0,anses[maxn];
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=0;d;d>>=1,i++)
		if(d&1)u=fa[u][i];
	if(u==v)return u;
	for(int i=18;i>=0;--i)if(fa[u][i]^fa[v][i])
		u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void dfs(int u,int _fa){
	a[++tp]=u,f[u]=tp,fa[u][0]=_fa;
	for(int i=1;fa[u][i-1];i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=_fa)
		dep[e[t].r]=dep[u]+1,dfs(e[t].r,u);
	a[++tp]=u,g[u]=tp;
}
int comp(const query& a,const query& b){
	return a.kl==b.kl?a.r<b.r:a.kl<b.kl;
}
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
void add(int x){
	if(!vis[x]){
		if(isboy[x])ans+=girls[num[x]],boys[num[x]]++;
		else ans+=boys[num[x]],girls[num[x]]++;
	} else {
		if(isboy[x])ans-=girls[num[x]],boys[num[x]]--;
		else ans-=boys[num[x]],girls[num[x]]--;
	}
	vis[x]^=1;
}
int main(){
	scanf("%d",&n),kuai=sqrt(n)+1;
	for(int i=1;i<=n;++i)scanf("%d",&isboy[i]);
	for(int i=1;i<=n;++i)scanf("%d",&num[i]),lsh[++sz]=num[i];
	for(int i=2,u,v;i<=n;++i)scanf("%d%d",&u,&v),addedge(u,v);
	sort(lsh+1,lsh+sz+1),sz=unique(lsh+1,lsh+sz+1)-lsh-1;
	for(int i=1;i<=n;++i)num[i]=lower_bound(lsh+1,lsh+sz+1,num[i])-lsh;
	tp=0,dfs(1,0),scanf("%d",&m);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(f[u]>f[v])swap(u,v);
		q[i].l=(lca(u,v)==u?f[u]:g[u]);
		q[i].r=f[v],q[i].bh=i,q[i].kl=q[i].l/kuai+1;
	}
	sort(q+1,q+m+1,comp);
	int pos=1;
	while(pos<=m){
		ans=0;
		for(int i=1;i<=sz;++i)boys[i]=girls[i]=0;
		for(int i=1;i<=n;++i)vis[i]=0;
		for(int i=q[pos].l;i<=q[pos].r;++i)add(a[i]);
		int z=lca(a[q[pos].l],a[q[pos].r]);
		if(z!=a[q[pos].l]&&z!=a[q[pos].r])
			add(z),anses[q[pos].bh]=ans,add(z);
		else anses[q[pos].bh]=ans;
		for(pos++;q[pos].kl==q[pos-1].kl&&pos<=m;pos++){
			for(int i=q[pos-1].l;i<q[pos].l;++i)add(a[i]);
			for(int i=q[pos-1].l-1;i>=q[pos].l;--i)add(a[i]);
			for(int i=q[pos-1].r;i>q[pos].r;--i)add(a[i]);
			for(int i=q[pos-1].r+1;i<=q[pos].r;++i)add(a[i]);
			int z=lca(a[q[pos].l],a[q[pos].r]);
			if(z!=a[q[pos].l]&&z!=a[q[pos].r])
				add(z),anses[q[pos].bh]=ans,add(z);
			else anses[q[pos].bh]=ans;
		}
	}
	for(int i=1;i<=m;++i)printf("%lld\n",anses[i]);
}