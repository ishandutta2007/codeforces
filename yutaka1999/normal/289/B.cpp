#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define INF 1000000000

using namespace std;

int n,m,d;
int in[105][105];
int fir=-1;

int main()
{
	scanf("%d %d %d",&n,&m,&d);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&in[i][j]);
			if(fir==-1) fir=in[i][j]%d;
			else if(in[i][j]%d!=fir)
			{
				printf("%d\n",-1);
				return 0;
			}
		}
	}
	int ret=INF;
	for(int s=fir;s<=10005;s+=d)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				sum+=abs(in[i][j]-s)/d;
			}
		}
		ret=min(ret,sum);
	}
	printf("%d\n",ret);
	return 0;
}