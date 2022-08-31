#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 42

using namespace std;

int cnt[SIZE][SIZE][SIZE][SIZE];
int rui[SIZE][SIZE];
char str[SIZE];

int sum(int a,int b,int c,int d)
{
	int ret=rui[c][d];
	if(a>0) ret-=rui[a-1][d];
	if(b>0) ret-=rui[c][b-1];
	if(a>0&&b>0) ret+=rui[a-1][b-1];
	return ret;
}
int main()
{
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		for(int j=0;j<m;j++)
		{
			rui[i][j]=str[j]-'0';
			if(i>0) rui[i][j]+=rui[i-1][j];
			if(j>0) rui[i][j]+=rui[i][j-1];
			if(i>0&&j>0) rui[i][j]-=rui[i-1][j-1];
		}
	}
	for(int a=n-1;a>=0;a--)
	{
		for(int c=a;c<n;c++)
		{
			for(int b=m-1;b>=0;b--)
			{
				for(int d=b;d<m;d++)
				{
					cnt[a][c][b][d]=sum(a,b,c,d)==0;
					if(b<d)
					{
						cnt[a][c][b][d]+=cnt[a][c][b][d-1];
						cnt[a][c][b][d]+=cnt[a][c][b+1][d];
						if(b+1<=d-1) cnt[a][c][b][d]-=cnt[a][c][b+1][d-1];
					}
				}
			}
		}
	}
	for(int a=n-1;a>=0;a--)
	{
		for(int c=a+1;c<n;c++)
		{
			for(int b=0;b<m;b++)
			{
				for(int d=b;d<m;d++)
				{
					cnt[a][c][b][d]+=cnt[a+1][c][b][d];
					cnt[a][c][b][d]+=cnt[a][c-1][b][d];
					if(a+1<=c-1) cnt[a][c][b][d]-=cnt[a+1][c-1][b][d];
				}
			}
		}
	}
	for(int i=0;i<q;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);a--;b--;c--;d--;
		printf("%d\n",cnt[a][c][b][d]);
	}
	return 0;
}