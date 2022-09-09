#include<bits/stdc++.h>
using namespace std;
const int N=55;
long double f[N][N],g[N];
vector<int>e[N];
int n,u,v,i,j,U;
int sz[N];
void dfs(int x,int fa){
	f[x][0]=1;sz[x]=1;
	for(int y:e[x])if(y!=fa){
		dfs(y,x);
		memset(g,0,sizeof g);
		for(i=0;i<=sz[x];++i)for(j=0;j<=sz[y];++j)g[i+j]+=f[x][i]*f[y][j];
		sz[x]+=sz[y];memcpy(f[x],g,sizeof g);
	}
	if(fa){
		memcpy(g,f[x],sizeof g);
		for(i=0;i<=sz[x];++i)g[i+1]-=f[x][i];
		for(i=1;i<=sz[x];++i)g[i]+=f[x][i-1]/i/2;
		memcpy(f[x],g,sizeof g);
	}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	for(U=1;U<=n;++U){
		memset(f,0,sizeof f);
		dfs(U,0);
		long double ans=0;for(i=0;i<N;++i)ans+=f[U][i];
		printf("%.8f\n",(double)ans);
	}
	return 0;
}