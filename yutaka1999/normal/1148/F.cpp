#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#include <cmath>
#include <cassert>
#define SIZE 300005
#define MX 65

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

vector <P> query[MX];

ll solve(int d,ll sum)
{
	ll nsum=sum;
	for(int i=0;i<query[d].size();i++)
	{
		P p=query[d][i];
		nsum-=p.first;
	}
	if(nsum==0)
	{
		ll ret=0;
		if(sum>0) ret=1LL<<d;
		return ret;
	}
	ll gt=solve(d-1,nsum);
	ll now=0;
	for(int i=0;i<query[d].size();i++)
	{
		P p=query[d][i];
		ll b=p.second&gt;
		int c=0;
		for(int j=0;j<d;j++) if(b>>j&1) c++;
		if(c%2==0) now+=p.first;
		else now-=p.first;
	}
	if(now>0) gt|=1LL<<d;
	return gt;
}
int main()
{
	int n;
	scanf("%d",&n);
	ll sum=0;
	for(int i=0;i<n;i++)
	{
		ll vl,mask;
		scanf("%lld %lld",&vl,&mask);
		sum+=vl;
		ll now=mask;
		int t=0;
		while(now>0)
		{
			now/=2;
			t++;
		}t--;
		query[t].push_back(P(vl,mask));
	}
	if(sum<0)
	{
		for(int i=0;i<MX;i++)
		{
			for(int j=0;j<query[i].size();j++)
			{
				query[i][j].first*=-1;
			}
		}
		sum*=-1;
	}
	printf("%lld\n",solve(MX-2,sum));
	return 0;
}