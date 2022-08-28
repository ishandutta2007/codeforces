#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <cstring>
#define SIZE 105
#define INF 1000000000

using namespace std;
typedef pair <int,int> P;
typedef pair <int,int> PP;

P st[SIZE];
int s[SIZE][SIZE];
int a[SIZE];
int n,d;
int dist(P l,P r)
{
	return abs(l.first-r.first)+abs(l.second-r.second);
}
int main()
{
	scanf("%d %d",&n,&d);
	a[0]=0;a[n-1]=0;
	for(int i=1;i<n-1;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		st[i]=P(x,y);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j) s[i][j]=0;
			else s[i][j]=dist(st[i],st[j])*d-a[j];
		}
	}
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
			}
		}
	}
	printf("%d\n",s[0][n-1]);
	return 0;
}