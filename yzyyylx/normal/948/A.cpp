#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define C ch=getchar()
#define N 10100
using namespace std;

int n,m;
char ans[510][510],ch;

int main()
{
	register int i,j,p,q,k;
	cin>>n>>m;
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			for(C; ch!='.'&&ch!='S'&&ch!='W'; C);
			ans[i][j]=ch;
			if(ch=='.') ans[i][j]='D';
			if(ch=='S')
			{
				if(ans[i-1][j]=='W'||ans[i][j-1]=='W')
				{
					puts("No");
					return 0;
				}
			}
			if(ch=='W')
			{
				if(ans[i-1][j]=='S'||ans[i][j-1]=='S')
				{
					puts("No");
					return 0;
				}
			}
		}
	}
	puts("Yes");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=m; j++)
		{
			printf("%c",ans[i][j]);
		}
		puts("");
	}
}