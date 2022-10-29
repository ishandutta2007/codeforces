#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define inf (1<<24) 
using namespace std;
int dp[10][310][310],s[310][310],px[310][310],n,m;
bool check(int k){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			s[i][j]=inf;
	memset(px,0x3f,sizeof(px));
	for(int p=0;k>>p;p++)if((k>>p)&1){
		for(int z=1;z<=n;++z)for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
			px[i][j]=min(px[i][j],min(s[i][z]+dp[p][z][j],dp[p][i][z]+s[z][j]));
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)s[i][j]=min(s[i][j],min(px[i][j],dp[p][i][j]));
		memset(px,0x3f,sizeof(px));
	}
	for(int i=1;i<=n;++i)if(s[i][i]<0)return true;
	return false;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			for(int k=0;(n<<1)>>k;++k)
				dp[k][i][j]=inf;
	for(int i=1,u,v,a,b;i<=m;++i)
		scanf("%d%d",&u,&v),
		scanf("%d%d",&a,&b),
		dp[0][u][v]=min(dp[0][u][v],-a),
		dp[0][v][u]=min(dp[0][v][u],-b);
	for(int p=1;(n<<1)>>p;++p)for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)
			dp[p][i][j]=min(dp[p-1][i][k]+dp[p-1][k][j],dp[p][i][j]);
	int l=1,r=n;
//	printf("[%d]",check(7));
	while(l<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(check(l))printf("%d",l);
	else printf("0");
}