#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
typedef long long int ll;
typedef pair <int,ll> P;

P ok(ll x)
{
	ll g=x;
	x--;
	if(x<=1) return P(-1,-1);
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			while(x%i==0) x/=i;
			if(x!=1) return P(-1,-1);
			return P(i,g);
		}
	}
	return P(x,g);
}
int main()
{
	ll n;
	scanf("%I64d",&n);
	vector <ll> gn;
	vector <P> div;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			gn.push_back(i);
			P p=ok(i);
			if(p.first!=-1) div.push_back(p);
			if(i!=n/i)
			{
				gn.push_back(n/i);
				p=ok(n/i);
				if(p.first!=-1) div.push_back(p);
			}
		}
	}
	sort(gn.begin(),gn.end());
	vector <ll> dp;
	dp.resize(gn.size());
	dp[gn.size()-1]=1;
	sort(div.begin(),div.end());
	for(int i=0;i<div.size();)
	{
		int s=i;
		vector <ll> dp1;
		for(int j=0;j<dp.size();j++) dp1.push_back(dp[j]);
		for(;i<div.size()&&div[s].first==div[i].first;i++)
		{
			ll d=div[i].second;
			for(int j=0;j<gn.size();j++)
			{
				if(dp[j]==0||gn[j]%d!=0) continue;
				ll nxt=gn[j]/d;
				int pos=lower_bound(gn.begin(),gn.end(),nxt)-gn.begin();
				if(pos<gn.size()&&gn[pos]==nxt)
				{
					dp1[pos]+=dp[j];
				}
			}
		}
		dp=dp1;
	}
	printf("%I64d\n",dp[0]);
	return 0;
}