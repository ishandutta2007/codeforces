#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define MX 100003

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

P dp[SIZE];//dp[i]:i^3<=x<(i+1)^3max
ll gt[SIZE];

int main()
{
	ll m;
	scanf("%lld",&m);
	for(int i=0;i<SIZE;i++) gt[i]=(ll) i*(ll) i*(ll) i;
	dp[0]=P(0,0);
	for(int i=1;i<MX;i++)
	{
		ll zan=gt[i+1]-1;
		ll cnt=0,sum=0;
		dp[i]=P(0,0);
		while(zan>0)
		{
			int s=0,e=MX+1;
			while(e-s>1)
			{
				int d=(s+e)/2;
				if(gt[d]<=zan) s=d;
				else e=d;
			}
			cnt+=zan/gt[s]-1;
			sum+=(zan/gt[s]-1)*gt[s];
			dp[i]=max(dp[i],P(dp[s-1].first+cnt,dp[s-1].second+sum));
			cnt++;
			sum+=gt[s];
			zan%=gt[s];
		}
		dp[i]=max(dp[i],P(cnt,sum));
		//if(i<=15) printf("%d : %lld %lld\n",i,dp[i].first,dp[i].second);
	}
	P ret=P(0,0);
	ll cnt=0,zan=m;
	ll sum=0;
	while(zan>0)
	{
		int s=0,e=MX+1;
		while(e-s>1)
		{
			int d=(s+e)/2;
			if(gt[d]<=zan) s=d;
			else e=d;
		}
		cnt+=zan/gt[s]-1;
		sum+=(zan/gt[s]-1)*gt[s];
		ret=max(ret,P(dp[s-1].first+cnt,dp[s-1].second+sum));
		cnt++;
		sum+=gt[s];
		zan%=gt[s];
	}
	ret=max(ret,P(cnt,sum));
	printf("%lld %lld\n",ret.first,ret.second);
	return 0;
}