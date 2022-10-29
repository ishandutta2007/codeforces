#include<cstdio>
#include<cstring>
using namespace std;
int a[110][110];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=(n-1)/2;j++)
			{
				if(i+j>n)break;
				a[i][i+j]=1;
			}
			for(int j=n/2+1;j<=n-1;j++)
			{
				a[i][i+j]=-1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)printf("%d%c",a[i][j],i==n-1&&j==n?'\n':' ');
		}
	}
	return 0;
}