#include<bits/stdc++.h>
using namespace std;
typedef double ldb;
const int N=60;
ldb f[N][N],C[N][N],tmp[N],G[N];
int n,sz[N];
vector<int>A[N];
void dfs(int u,int fa){
	sz[u]=0;
	f[u][0]=1;
	for(auto v:A[u])if(v!=fa){
		dfs(v,u);
		for(int i=0;i<=sz[v];++i)tmp[i]=0;
		for(int i=0;i<=sz[v];++i)
			for(int j=1;j<=sz[v];++j)
				tmp[i]+=f[v][min(i,j-1)]*(j<=i?0.5:1);
		for(int i=0;i<=sz[u]+sz[v];++i)G[i]=0;
		for(int i=0;i<=sz[u];++i)
			for(int j=0;j<=sz[v];++j)
				G[i+j]+=f[u][i]*tmp[j]*C[i+j][j]*C[sz[u]+sz[v]-i-j][sz[v]-j];
		for(int i=0;i<=sz[u]+sz[v];++i)f[u][i]=G[i];
		sz[u]+=sz[v];
	}
	sz[u]++;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;++i)
		for(int j=*C[i]=1;j<=i;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1]);
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		A[u].push_back(v);
		A[v].push_back(u);
	}
	ldb fac=1;
	for(int i=1;i<=n-1;++i)fac*=i;
	for(int i=1;i<=n;++i){
		dfs(i,0);
		printf("%.10lf\n",f[i][n-1]/fac);
	}
}