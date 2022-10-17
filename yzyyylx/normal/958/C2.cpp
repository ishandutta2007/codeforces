#pragma GCC optimize("Ofast")
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ans[2][102][202],anss=-0x3f3f3f3f;
int a[20100];
int n,x,p,now;
//jk
int main()
{
	int i,j,k;
	scanf("%d%d%d",&n,&x,&p);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	memset(ans[0],192,sizeof(ans[0]));now=0;
	ans[0][0][0]=0;
	for(i=0;i<n;i++)
	{
		memset(ans[now^1],192,sizeof(ans[now^1]));
		for(j=0;j<=x;j++)
		{
			for(k=0;k<p;k++)
			{
				ans[now^1][j+1][0]=max(ans[now^1][j+1][0],ans[now][j][k]+(k+a[i+1])%p);
				ans[now^1][j][(k+a[i+1])%p]=max(ans[now^1][j][(k+a[i+1])%p],ans[now][j][k]);
			}
		}
		now^=1;
	}
	printf("%d",ans[now][x][0]);
	return 0;
}