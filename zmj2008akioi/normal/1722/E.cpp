#include <cstdio>
#include <algorithm>
const int N=1e3+10;
int T,n,q;
long long sum[N][N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&n,&q);
		for(int i=1;i<=1000;++i)for(int j=1;j<=1000;++j)sum[i][j]=0;
		for(int x,y,i=1;i<=n;++i){
			scanf("%d %d",&x,&y);
			sum[x][y]+=x*y;
		}
		for(int i=1;i<=1000;++i)for(int j=1;j<=1000;++j)sum[i][j]+=sum[i][j-1];
		for(int i=1;i<=1000;++i)for(int j=1;j<=1000;++j)sum[i][j]+=sum[i-1][j];
		for(int sx,sy,tx,ty,i=1;i<=q;++i){
			scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
			printf("%lld\n",sum[sx][sy]+sum[tx-1][ty-1]-sum[sx][ty-1]-sum[tx-1][sy]);
		}
	}
	return 0;
}