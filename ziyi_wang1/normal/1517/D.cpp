#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,valr[510][510],valc[510][510],dis[510][510][11];
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	if(k&1)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				printf("-1%c",j==m?'\n':' ');
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			scanf("%d",&valr[i][j]);
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&valc[i][j]);
	k/=2;
	for(int l=1;l<=k;++l)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				dis[i][j][l]=0x3f3f3f3f;
				if(j<m)dis[i][j][l]=min(dis[i][j][l],dis[i][j+1][l-1]+valr[i][j]);
				if(j>1)dis[i][j][l]=min(dis[i][j][l],dis[i][j-1][l-1]+valr[i][j-1]);
				if(i<n)dis[i][j][l]=min(dis[i][j][l],dis[i+1][j][l-1]+valc[i][j]);
				if(i>1)dis[i][j][l]=min(dis[i][j][l],dis[i-1][j][l-1]+valc[i-1][j]);
			}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			printf("%d%c",2*dis[i][j][k],j==m?'\n':' ');
	return 0;
}