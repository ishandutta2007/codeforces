#include<bits/stdc++.h>
#define N 52
using namespace std;
int S,n,m,tot,at[N];
int f[N][N][N][N];
bool suan[N][N][N][N];
int dis[N][N],head[N],du[N];
struct edge{int to,next,v;}e[N*2];
int dp(int u,int v,int out,int in){
	if (!out&&!in) return 0;
	if (suan[u][v][out][in])
		return f[u][v][out][in];
	suan[u][v][out][in]=1;
	if (du[v]==1){
		if (!out) return 0;
		return f[u][v][out][in]=dp(v,u,0,out)+dis[v][u];
	}
	int g[N];
	for (int i=0;i<=in;i++)
		g[i]=-(1<<30)+233;
	g[0]=(1<<30)-233;
	for (int i=head[v];i;i=e[i].next)
		if (e[i].to!=u){
			int y=e[i].to;
			for (int j=in;j>=1;j--)
				for (int k=1;k<=j;k++)
					g[j]=max(g[j],min(g[j-k],dp(v,y,out+in-k,k)+dis[v][y]));
		}
	return f[u][v][out][in]=g[in];
}
int dfs(int x,int ff){
	int ans=at[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=ff) ans+=dfs(e[i].to,x);
	return ans;
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y,z; scanf("%d%d%d",&x,&y,&z);
		add(x,y,z); add(y,x,z);
		dis[x][y]=dis[y][x]=z;
		du[x]++; du[y]++;
	}
	scanf("%d%d",&S,&m);
	for (int i=1,x;i<=m;i++)
		scanf("%d",&x),at[x]++;
	int ans=1<<30;
	for (int i=head[S];i;i=e[i].next){
		int num=dfs(e[i].to,S);
		if (num) ans=min(ans,dp(S,e[i].to,m-num,num)+e[i].v);
	}
	printf("%d",ans);
}