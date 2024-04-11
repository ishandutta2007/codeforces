#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005

using namespace std;
typedef long double ld;

ld dp[2][SIZE];

void fill(int pos)
{
	for(int i=0;i<SIZE;i++)
	{
		dp[pos][i]=0.0;
	}
}
int main()
{
	int n,T;
	scanf("%d %d",&n,&T);
	int pos=0;
	fill(pos);
	dp[pos][0]=1.0;
	ld ret=0.0;
	for(int i=0;i<n;i++)
	{
		int p,t;
		scanf("%d %d",&p,&t);
		ld per=(ld) p/100.0,gan=0.0;
		for(int j=0;j<t-1;j++)
		{
			gan+=per;
			per*=(ld) (100-p)/100.0;
		}
		pos^=1;
		fill(pos);
		ld sum=0.0;
		for(int j=0;j<=T;j++)
		{
			sum*=(ld) (100-p)/100.0;
			if(j>0) sum+=dp[pos^1][j-1]*(ld) p/100.0;
			if(j>=t) sum-=dp[pos^1][j-t]*per;
			dp[pos][j]=sum;
			if(j>=t)
			{
				dp[pos][j]+=dp[pos^1][j-t]*(1.0-gan);
			}
			ret+=dp[pos][j];
		}
	}
	printf("%.10f\n",(double) ret);
	return 0;
}