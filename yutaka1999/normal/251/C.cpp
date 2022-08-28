#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define LCM 360360
#define INF 1000000000

using namespace std;
typedef long long int ll;

int dp[LCM+5];
int k;

ll calc(int a,int b)//a>=b
{
	memset(dp,-1,sizeof(dp));
	dp[a]=0;
	queue <int> que;
	que.push(a);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		if(v==0) continue;
		if(dp[v-1]==-1)
		{
			dp[v-1]=dp[v]+1;
			que.push(v-1);
		}
		for(int i=1;i<=k;i++)
		{
			int gen=v%i;
			if(dp[v-gen]==-1)
			{
				dp[v-gen]=dp[v]+1;
				que.push(v-gen);
			}
		}
	}
	return (ll) dp[b];
}
int main()
{
	ll a,b;
	scanf("%llld %llld %d",&a,&b,&k);
	if(a/LCM==b/LCM)
	{
		printf("%llld\n",calc((int) (a%LCM),(int) (b%LCM)));
		return 0;
	}
	ll ret=0;
	if(a%LCM!=0)
	{
		ret+=calc((int) (a%LCM),0);
		a-=a%LCM;
	}
	if(b%LCM!=0)
	{
		ret+=calc(LCM,(int) (b%LCM));
		b+=LCM-b%LCM;
	}
	ret+=(a-b)/LCM*calc(LCM,0);
	printf("%llld\n",ret);
	return 0;
}