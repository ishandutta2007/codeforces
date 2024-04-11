#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 1010
#define M 
using namespace std;

ll n,x[N],y[N],a[N],b[N];
bool use[N];
map<P,ll>mm;

inline bool check(ll u,ll v)
{
	ll i,j,p,q,t;
	for(i=1;i<=n;i++)
	{
		p=u-x[i];
		q=v-y[i];
		if(!mm.count(mp(p,q))) return 0;
	}
	return 1;
}

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
		mm[mp(a[i],b[i])]=i;
	}
	for(i=1;i<=n;i++)
	{
		if(check(a[i]+x[1],b[i]+y[1]))
		{
			cout<<a[i]+x[1]<<" "<<b[i]+y[1];
			return 0;
		}
	}
}