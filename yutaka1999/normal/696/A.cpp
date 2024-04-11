#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;
typedef long long int ll;

map <ll,ll> mp;

ll LCA(ll a,ll b)
{
	while(1)
	{
		while(a>b) a/=2;
		if(a==b) return a;
		b/=2;
	}
}
void add(ll a,ll b,ll w)
{
	ll p=LCA(a,b);
	while(a>p)
	{
		mp[a]+=w;
		a/=2;
	}
	while(b>p)
	{
		mp[b]+=w;
		b/=2;
	}
}
ll get(ll a,ll b)
{
	ll p=LCA(a,b);
	ll ret=0;
	while(a>p)
	{
		ret+=mp[a];
		a/=2;
	}
	while(b>p)
	{
		ret+=mp[b];
		b/=2;
	}
	return ret;
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int t;
		scanf("%d",&t);
		if(t==1)
		{
			ll a,b,w;
			scanf("%lld %lld %lld",&a,&b,&w);
			add(a,b,w);
		}
		else
		{
			ll a,b;
			scanf("%lld %lld",&a,&b);
			printf("%lld\n",get(a,b));
		}
	}
	return 0;
}