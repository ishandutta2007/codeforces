#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstring>
#define SIZE 1000005
#define BT 1<<12
#define MX 12

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll A[SIZE],memo[BT];
int E[SIZE];
ll dp[MX][BT];

ll gcd(ll x,ll y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n;
	ll lim;
	scanf("%d %lld",&n,&lim);
	ll g=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&A[i]);
		g=gcd(g,A[i]);
	}
	for(int i=0;i<n;i++) scanf("%d",&E[i]);
	vector <P> vx;
	vector <ll> pr;
	for(ll i=2;i*i<=g;i++)
	{
		if(g%i==0)
		{
			pr.push_back(i);
			while(g%i==0) g/=i;
		}
	}
	if(g!=1) pr.push_back(g);
	for(int i=0;i<n;i++)
	{
		ll a=1;
		for(int j=0;j<pr.size();j++)
		{
			ll p=pr[j];
			while(A[i]%p==0)
			{
				a*=p;
				A[i]/=p;
			}
		}
		vx.push_back(P(a,E[i]));
	}
	sort(vx.begin(),vx.end());
	int sz=0;
	for(int i=0;i<vx.size();i++)
	{
		if(i>=11&&vx[i-11].first==vx[i].first) continue;
		A[sz]=vx[i].first,E[sz]=vx[i].second;
		sz++;
	}n=sz;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int S=0;S<1<<pr.size();S++) memo[S]=1;
		for(int j=0;j<pr.size();j++)
		{
			ll p=pr[j];
			while(A[i]%p==0)
			{
				A[i]/=p;
				memo[1<<j]*=p;
			}
		}
		for(int S=0;S<1<<pr.size();S++)
		{
			for(int j=0;j<pr.size();j++)
			{
				if((S>>j&1)&&S!=(1<<j)) memo[S]*=memo[1<<j];
			}
		}
		for(int S=(1<<pr.size())-1;S>=0;S--)
		{
			for(int j=0;j<pr.size();j++)
			{
				if(dp[j][S]==-1) continue;
				int T=(1<<pr.size())-S-1;
				for(int K=T;K>0;K=(K-1)&T)
				{
					if(memo[K]<=lim)
					{
						if(dp[j+1][S+K]==-1) dp[j+1][S+K]=dp[j][S]+E[i];
						else dp[j+1][S+K]=min(dp[j+1][S+K],dp[j][S]+E[i]);
					}
				}
			}
		}
	}
	ll ret=-1;
	for(int i=0;i<=pr.size();i++)
	{
		if(dp[i][(1<<pr.size())-1]!=-1)
		{
			if(ret==-1) ret=dp[i][(1<<pr.size())-1]*(ll) i;
			else ret=min(ret,dp[i][(1<<pr.size())-1]*(ll) i);
		}
	}
	printf("%lld\n",ret);
	return 0;
}