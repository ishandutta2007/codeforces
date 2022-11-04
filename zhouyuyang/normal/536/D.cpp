#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 2005
struct edge{
	int to,next,v;
}e[N*105];
int head[N],tot,n;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
struct Graph{
	int S,sz;
	bool vis[N];
	ll dis[N],b[N];
	void work(){
		for (int i=1;i<=n;i++)
			if (i!=S) dis[i]=(1ll<<62);
		for (int i=1;i<=n;i++){
			int k=0;
			for (int j=1;j<=n;j++)
				if (!vis[j]&&(!k||dis[j]<dis[k]))
					k=j;
			vis[k]=1;
			for (int j=head[k];j;j=e[j].next)
				dis[e[j].to]=min(dis[e[j].to],dis[k]+e[j].v);
		}
		memcpy(b,dis,sizeof(b));
		sort(b+1,b+n+1);
		sz=unique(b+1,b+n+1)-b-1;
		for (int i=1;i<=n;i++)
			dis[i]=lower_bound(b+1,b+sz+1,dis[i])-b;
	}
}G[2];
int sz[N][N];
ll sum[N][N];
ll f[N][N][2][2];
bool vis[N][N][2][2];
int SZ(int x,int y,int X,int Y){
	return sz[x][y]-sz[X][Y];
}
ll SUM(int x,int y,int X,int Y){
	return sum[x][y]-sum[X][Y];
}
ll DP(int x,int y,int who,int can){
	if (x>G[0].sz||y>G[1].sz) return 0;
	if (vis[x][y][who][can])
		return f[x][y][who][can];
	vis[x][y][who][can]=1; ll ans;
	if (who) ans=DP(x,y+1,who,can||SZ(x,y,x,y+1))+SUM(x,y,x,y+1);
	else ans=DP(x+1,y,who,can||SZ(x,y,x+1,y))+SUM(x,y,x+1,y);
	if (can) ans=max(ans,-DP(x,y,who^1,0));
	return f[x][y][who][can]=ans;
}
int m,v[N];
int main(){
	scanf("%d%d%d%d",&n,&m,&G[0].S,&G[1].S);
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1;i<=m;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	G[0].work();
	G[1].work();
	for (int i=1;i<=n;i++){
		sz[G[0].dis[i]][G[1].dis[i]]++;
		sum[G[0].dis[i]][G[1].dis[i]]+=v[i];
	}
	for (int i=G[0].sz;i;i--)
		for (int j=G[1].sz;j;j--){
			sz[i][j]+=sz[i][j+1]+sz[i+1][j]-sz[i+1][j+1];
			sum[i][j]+=sum[i][j+1]+sum[i+1][j]-sum[i+1][j+1];
		}
	ll ans=DP(1,1,0,0);
	if (ans==0) puts("Flowers");
	else if (ans<0) puts("Cry");
	else puts("Break a heart");
}