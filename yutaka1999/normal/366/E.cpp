#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 2005
#define MX 12
#define INF 1000000000

using namespace std;

int mn[MX][2],mx[MX][2];
int len[MX][MX];
/*
(x,y) -> (x+y,x-y)
|x-x1|+|y-y1|
=max(|(x+y)-(x1+y1)|,|(x-y)-(x1-y1)|)
*/

int fx(int x,int y,int k)
{
	if(k==0) return x+y;
	return x-y;
}

int main()
{
	int n,m,k,s;
	scanf("%d %d %d %d",&n,&m,&k,&s);
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<2;j++)
		{
			mn[i][j]=INF;
			mx[i][j]=-INF;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int a;
			scanf("%d",&a);a--;
			for(int p=0;p<2;p++)
			{
				mn[a][p]=min(mn[a][p],fx(i,j,p));
				mx[a][p]=max(mx[a][p],fx(i,j,p));
			}
		}
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			len[i][j]=-INF;
			for(int p=0;p<2;p++)
			{
				len[i][j]=max(len[i][j],abs(mx[i][p]-mn[j][p]));
				len[i][j]=max(len[i][j],abs(mx[j][p]-mn[i][p]));
			}
		}
	}
	int ret=0;
	int bef;
	scanf("%d",&bef);bef--;
	for(int i=1;i<s;i++)
	{
		int a;
		scanf("%d",&a);a--;
		ret=max(ret,len[bef][a]);
		bef=a;
	}
	printf("%d\n",ret);
	return 0;
}