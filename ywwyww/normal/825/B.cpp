#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long ll;
const int maxint=0x7fffffff;
const int minint=0x80000000;
const ll maxll=0x7fffffffffffffffll;
const ll minll=0x8000000000000000ll;
int a[20][20];
int dx[]={0,1,0,1,1};
int dy[]={0,0,1,1,-1};
int check()
{
	int i,j,i2,j2,k;
	for(k=1;k<=4;k++)
	{
		for(i=1;i<=10;i++)
			for(j=1;j<=10;j++)
				if(i+4*dx[k]<=10&&i+4*dx[k]>=1&&j+4*dy[k]<=10&&j+4*dy[k]>=1)
				{
					int bb=1;
					for(i2=1;i2<=5;i2++)
					{
						int nx=i+(i2-1)*dx[k];
						int ny=j+(i2-1)*dy[k];
						if(a[nx][ny]!=1)
						{
							bb=0;
							break;
						}
					}
					if(bb)
						return 1;
				}
	}
	return 0;
}
int main()
{
	char s[20];
	int i,j;
	for(i=1;i<=10;i++)
	{
		scanf("%s",s+1);
		for(j=1;j<=10;j++)
			if(s[j]=='X')
				a[i][j]=1;
			else if(s[j]=='O')
				a[i][j]=2;
			else
				a[i][j]=0;
	}
	for(i=1;i<=10;i++)
		for(j=1;j<=10;j++)
			if(a[i][j]==0)
			{
				a[i][j]=1;
				if(check())
				{
					printf("YES\n");
					return 0;
				}
				a[i][j]=0;
			}
	printf("NO\n");
	return 0;
}