#include <cstdio>
const int N=110;
int T,n;bool dp[N][N][2];
bool get(int x,int y,int t){
	if(x<0||y<0)return true;
	return dp[x][y][t];
}
int main(){
	scanf("%d",&T);const int m=100;
	dp[0][0][0]=dp[0][1][0]=dp[1][0][1]=true;
	for(int t=2;t<=m;++t){
		for(int i=0;i<=t;++i){
			int x=i,y=t-i;bool *p=dp[x][y];
			if(x)for(int j=0;j<2;++j)p[j]|=get(x-1,y-1,j^1)&&get(x-2,y,j^1);
			if(y)for(int j=0;j<2;++j)p[j]|=get(x-1,y-1,j)&&get(x,y-2,j);
		}
	}
	while(T--){
		scanf("%d",&n);int c=0;
		for(int w,i=1;i<=n;++i)scanf("%d",&w),c+=w&1;
		puts(dp[c][n-c][0]?"Alice":"Bob");
	}
	return 0;
}