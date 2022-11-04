#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{int to,next;}e[N*2];
int n,m,q,tot=1,T,num,u,v,w,top,cnt;
int head[N],x[N],y[N],dep[N];
int dfn[N],low[N],inq[N],sta[N],c[N];
int fa[N][18],bz[N*2],bel[N],f[N],g[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void tarjan(int x){
	dfn[x]=low[x]=++T;
	sta[++top]=x;
	inq[x]=1; bel[x]=cnt;
	for (int i=head[x];i;i=e[i].next){
		if (bz[i]) continue;
		if (!dfn[e[i].to]){
			bz[i]=bz[i^1]=1;
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (inq[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	}
	if (low[x]==dfn[x]){
		num++;
		for (;sta[top+1]!=x;top--)
			c[sta[top]]=num,inq[sta[top]]=0;
	}
}
void dfs(int x,int y){
	dep[x]=dep[y]+1;
	fa[x][0]=y; bz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=y) dfs(e[i].to,x);
}
void get(int x){
	bz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			get(e[i].to);
			f[x]+=f[e[i].to];
			g[x]+=g[e[i].to];
		}
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=0;i<=17;i++,tmp/=2)
		if (tmp&1) x=fa[x][i];
	for (int i=17;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]); add(y[i],x[i]);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) ++cnt,tarjan(i);
	memset(head,0,sizeof(head));
	memset(bz,0,sizeof(bz));
	tot=0;
	for (int i=1;i<=m;i++)
		if (c[x[i]]!=c[y[i]]){
			add(c[x[i]],c[y[i]]);
			add(c[y[i]],c[x[i]]);
		}
	for (int i=1;i<=num;i++)
		if (!bz[i]) dfs(i,0);
	memset(bz,0,sizeof(bz));
	for (int i=1;i<=17;i++)
		for (int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	while (q--){
		scanf("%d%d",&u,&v);
		if (bel[u]!=bel[v])
			return puts("No"),0;
		u=c[u]; v=c[v]; w=lca(u,v);
		f[u]++; f[w]--; g[v]++; g[w]--;
	}
	for (int i=1;i<=num;i++)
		if (!bz[i]) get(i);
	for (int i=1;i<=num;i++)
		if (f[i]&&g[i])
			return puts("No"),0;
	puts("Yes");
}