#include<bits/stdc++.h>
using namespace std;
const int N=85;
int n,K,m,u,v,c,cc[N][N],f[2][N][N][2],i,j,k,nw,ans=1<<30;
int main(){
	memset(cc,1,sizeof cc);
	scanf("%d%d%d",&n,&K,&m);
	for(;m--;)scanf("%d%d%d",&u,&v,&c),cc[u][v]=min(cc[u][v],c);
	memset(f[0],1,sizeof f[0]);
	for(i=1;i<=n;++i)f[0][0][i][1]=f[0][i][n+1][0]=0;
	for(;--K;){
		nw^=1;memset(f[nw],1,sizeof f[nw]);
		for(i=0;i<=n-1;++i)for(j=i+2;j<=n+1;++j)for(k=i+1;k<j;++k){
			f[nw][i][k][1]=min(f[nw][i][k][1],min(f[!nw][i][j][1]+cc[j][k],f[!nw][i][j][0]+cc[i][k]));
			f[nw][k][j][0]=min(f[nw][k][j][0],min(f[!nw][i][j][0]+cc[i][k],f[!nw][i][j][1]+cc[j][k]));
		}
	}
	for(i=0;i<=n+1;++i)for(j=0;j<=n+1;++j)ans=min(ans,min(f[nw][i][j][0],f[nw][i][j][1]));
	if(ans>1<<20)ans=-1;
	printf("%d\n",ans);
}