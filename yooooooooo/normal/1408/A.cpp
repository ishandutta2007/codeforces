#include<cstdio>
#include<algorithm>
using namespace std;
int t,x;
int n,a[3][105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int _=0;_<3;_++)for(int i=0;i<n;i++)scanf("%d",&a[_][i]);
		printf("%d ",a[0][0]);x=a[0][0];
		for(int i=1;i<n-1;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(a[j][i]==x)continue;
				printf("%d ",a[j][i]);
				x=a[j][i];
				break;
			}
		}
		for(int j=0;j<3;j++)
		{
			if(a[j][n-1]==x||a[j][n-1]==a[0][0])continue;
			printf("%d\n",a[j][n-1]);
			break;
		}
	}
	return 0;
}