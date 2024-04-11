#include<bits/stdc++.h>
#define ll long long
#define pa pair<ll,int>
#define N 200005
using namespace std;
priority_queue<pa > q;
struct edge{int to,next,v;}e[N*3];
int head[N],vis[N],id[N];
int fa[N][20],dep[N],sz[N];
int n,m,s,tot,ans,cnt;
ll dis[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dijk(){
	for (int i=1;i<=n;i++)
		dis[i]=1e18,vis[i]=0;
	dis[s]=0; q.push(pa(0,s));
	while (!q.empty()){
		int x=q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x]=1; id[++cnt]=x;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].v){
				dis[e[i].to]=dis[x]+e[i].v;
				q.push(pa(-dis[e[i].to],e[i].to));
			}
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
	scanf("%d%d%d",&n,&m,&s);
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dijk();
	fa[s][0]=0; dep[s]=1;
	for (int i=2;i<=n;i++)
		if (dis[id[i]]<1e18){
			int l=0,x=id[i];
			for (int j=head[x];j;j=e[j].next)
				if (dis[e[j].to]+e[j].v==dis[x])
					l=(l?lca(l,e[j].to):e[j].to);
			fa[x][0]=l; dep[x]=dep[l]+1;
			for (int j=1;j<=17;j++)
				fa[x][j]=fa[fa[x][j-1]][j-1];
		}
	for (int i=1;i<=n;i++)
		sz[i]=1;
	for (int i=n;i>=2;i--)
		if (dis[id[i]]<1e18){
			int x=id[i];
			sz[fa[x][0]]+=sz[x];
			ans=max(ans,sz[x]);
		}
	printf("%d\n",ans);
}