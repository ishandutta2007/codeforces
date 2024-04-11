#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 22
#define BT (1<<21)
#define EPS 1e-10

using namespace std;
typedef double ld;

ld dp[BT];
ld pb[SIZE];
ld ans[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%lf",&pb[i]);
	dp[0]=1.0;
	for(int S=0;S<1<<n;S++)
	{
		if(dp[S]<EPS) continue;
		int cnt=0;
		ld all=0.0;
		for(int i=0;i<n;i++)
		{
			if(S>>i&1) cnt++;
			else all+=pb[i];
		}
		if(cnt==k||(cnt<k&&all<EPS))
		{
			for(int i=0;i<n;i++)
			{
				if(S>>i&1)
				{
					ans[i]+=dp[S];
				}
			}
			continue;
		}
		for(int i=0;i<n;i++)
		{
			if(!(S>>i&1))
			{
				dp[S|1<<i]+=dp[S]*pb[i]/all;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%.10f",(double) ans[i]);
	}puts("");
	return 0;
}