#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,m;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==n&&j==m&&n*m%2==0)printf("B");
				else
				{
					if((n*m%2&&(i+j)%2==0)||(n*m%2==0&&(i+j)%2!=(n+m)%2))printf("B");
					else printf("W");
				}
			}
			printf("\n");
		}
	}
	return 0;
 }