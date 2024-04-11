#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=5e2+10;
int t;
int n,m;
int cell[maxn][maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char c;cin>>c;
				if(c=='X')cell[i][j]=1;
				else cell[i][j]=0;
			}
		}
		for(int i=1;i<=n;i+=3)
		{
			for(int j=1;j<=m;j++)cell[i][j]=1;
		}
		for(int i=2;i<=n-2;i+=3)
		{
			if(!cell[i][2]&&!cell[i+1][2])cell[i][1]=cell[i+1][1]=1;
			else cell[i][2]=cell[i+1][2]=1;
		}
		if(n%3==0)
		{
			for(int j=1;j<=m;j++)if(cell[n][j])cell[n-1][j]=1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(cell[i][j])printf("X");
				else printf(".");
			}
			printf("\n");
		}
	}
	return 0;
}