#include <cstdio>
#include <algorithm>
#define x first
#define y second
#define ll long long
using std::pair;
const int N=400005;
int T, n;
ll res, k, len[N], smx[N], x, pr;
pair<ll, ll> p[N];
inline ll calc(ll x)
{
	ll ret=0;
	for(int i=1; i<=n; ++i) ret+=((len[i]+1+x)/(x+1))-1;
	return ret;
}
inline ll calc1(ll x)
{
	ll ret=0;
	for(int i=1; i<=n; ++i) ret+=((len[i]+1)/(x+1))-1;
	return ret;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%d%lld", &res, &n, &k);
		pr=0;
		for(int i=1; i<=n; ++i)
		{
			scanf("%lld", &x);
			len[i]=x-pr-1;
			pr=x;
		}
		len[++n]=res-pr-1;
		ll l=0, r=1e15, mn, mx;
		while(l<r)
		{
			ll mid=(l+r)>>1;
			if(calc(mid)>k) l=mid+1;
			else r=mid;
		}
		mx=l;
		l=0;
		for(int i=1; i<=n; ++i) r=std::min(r, len[i]);
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			if(calc1(mid)<k) r=mid-1;
			else l=mid;
		}
		mn=l;
		for(int i=1; i<=n; ++i)
		{
			ll c=((len[i]+1+mx)/(mx+1))-1;
			ll a=(len[i]+1)/(c+1)-1;
			c=((len[i]+1)/(mn+1))-1;
			ll b=(len[i]+1+c)/(c+1)-1;
			p[i]={a, b};
		}
		std::sort(p+1, p+n+1);
		for(int i=1; i<=n; ++i) smx[i]=std::max(smx[i-1], p[i].y);
		ll ans=0x3f3f3f3f3f3f3f;
		for(int i=1; i<=n; ++i)
		{
			ll l=std::min(mn, p[i].x), r=std::max(mx, smx[i-1]);
			ans=std::min(ans, r-l);
		}
		printf("%lld\n", ans);
	}
	return 0;
}