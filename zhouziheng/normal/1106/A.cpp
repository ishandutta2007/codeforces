#include<cstdio>

using namespace std;

char c[601][601]={};

int main()
{
	int n=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf(" %c",&c[i][j]);
		}
	}
	int ans=0;
	for(int i=2;i<n;i++)
	{
		for(int j=2;j<n;j++)
		{
			if(c[i][j]=='X'&&c[i-1][j-1]=='X'
			&&c[i-1][j+1]=='X'&&c[i+1][j-1]=='X'&&c[i+1][j+1]=='X')
			{
				ans++;
			}
		}
	}
	printf("%d",ans);return 0;
}