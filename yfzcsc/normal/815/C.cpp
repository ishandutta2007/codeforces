#include<bits/stdc++.h>
#define inf (b+1000)
#define maxn 5010
using namespace std;
typedef long long ll;
struct edge{
	int r,nxt;
}e[maxn<<1];
int size[maxn],head[maxn],esz,b,d[maxn],c[maxn],n;
int f[maxn][maxn],g[maxn][maxn];
void dfs(int u){
	size[u]=1;
	for(int t=head[u];t;t=e[t].nxt)
		dfs(e[t].r),size[u]+=size[e[t].r];
	for(int i=0;i<=size[u];++i)f[u][i]=g[u][i]=inf;
	size[u]=1;
	f[u][0]=0,f[u][1]=c[u];
	g[u][1]=c[u]-d[u];
	for(int t=head[u];t;t=e[t].nxt){
		for(int j=size[u];j>=0;--j)
			for(int k=0;k<=size[e[t].r];++k)
				f[u][j+k]=min(f[u][j+k],f[u][j]+f[e[t].r][k]),
				g[u][j+k]=min(g[u][j+k],g[u][j]+min(f[e[t].r][k],g[e[t].r][k]));
		size[u]+=size[e[t].r];
	}
}
int main(){
	scanf("%d%d",&n,&b);
	scanf("%d%d",&c[1],&d[1]);
	for(int i=2,fa;i<=n;++i){
		scanf("%d%d%d",&c[i],&d[i],&fa);
		e[++esz].r=i;e[esz].nxt=head[fa];head[fa]=esz;
	}
	dfs(1);
	for(int i=n;i>=0;--i)if(min(f[1][i],g[1][i])<=b)return printf("%d\n",i),0;
}