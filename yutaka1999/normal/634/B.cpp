#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define MX 42
#define SIZE 8

using namespace std;
typedef long long int ll;

ll dp[2][SIZE];//S-(a)

int main()
{
	ll S,x;
	scanf("%lld %lld",&S,&x);
	int pos=0;
	memset(dp[pos],0,sizeof(dp[pos]));
	dp[pos][0]=1;
	for(int i=MX-1;i>=0;i--)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		int d=0;
		if(x>>i&1) d=1;
		for(int j=0;j<SIZE;j++)
		{
			if(dp[pos^1][j]==0) continue;
			for(int a=0;a<2;a++)
			{
				for(int b=0;b<2;b++)
				{
					if((a^b)!=d) continue;
					int nxt=2*j-(a+b);
					if(S>>i&1) nxt++;
					if(0<=nxt&&nxt<SIZE) dp[pos][nxt]+=dp[pos^1][j];
				}
			}
		}
	}
	if(S==x) dp[pos][0]-=2;
	printf("%lld\n",dp[pos][0]);
	return 0;
}