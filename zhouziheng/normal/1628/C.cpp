#include<cstdio>
#include<algorithm>

using namespace std;

int a[2000][2000];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
		int ans=0;
		for(int i=1;i<=n;i+=2)for(int j=1;j+i<=n;j++)if((i+j+n)%4==0)ans^=a[i][j]/*,printf("%d %d\n",i,j)*/;
		for(int i=2;i<=n;i+=2)for(int j=n;j+i>n+2;j--)if((i+j+n)%4==0)ans^=a[i][j]/*,printf("%d %d\n",i,j)*/;
		for(int i=1;i<=n/2;i++)for(int j=1;j<=n;j++)swap(a[i][j],a[n+1-i][j]);
		for(int i=1;i<=n;i+=2)for(int j=1;j+i<=n;j++)if((i+j+n)%4==0)ans^=a[i][j]/*,printf("%d %d\n",i,j)*/;
		for(int i=2;i<=n;i+=2)for(int j=n;j+i>n+2;j--)if((i+j+n)%4==0)ans^=a[i][j]/*,printf("%d %d\n",i,j)*/;
		printf("%d\n",ans);
	}
}