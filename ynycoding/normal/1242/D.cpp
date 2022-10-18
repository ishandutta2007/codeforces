#include <cstdio>
#include <tuple>
#include <algorithm>
#define ll long long
#define mp std::make_tuple
using std::tuple;
int T, k, res;
ll n;
// l of the same round; r of the same round; vacant pos; number of round-1; round if n is vac
tuple<ll, ll, ll, ll, ll> solve(ll n)
{
	if(2*n<1ll*k*(k+1)) return mp((n-1)/k*k+1, ((n-1)/k+1)*k, 0, (n-1)/k, 0);
	ll vl=(2*n/k-k+1)/2;
	auto [l, r, p, v, v1]=solve(vl+k-1);
	if((r-l+1)*(l+r)/2-p==n)
	{
		ll res=n-1-v, rd=res/k;
		return mp(rd*k+v+1, rd*k+v+k+1, n, rd, v+1);
	}
	{
		ll s=(l+r)*(r-l+1)/2-p;
		if(s<n) ++v;
		ll res=n-1-v;
		ll rd=res/k;
		ll tl=rd*k+v+1, tr=tl+k-1, tp=0;
		if(s>=n&&s-tl<k) ++tr, tp=s;
		else if(s>=tl&&s<n) --tl, tp=s;
		return mp(tl, tr, tp, rd, 0);
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%lld%d", &n, &k);
		auto [l, r, p, v, v1]=solve(n);
		printf("%lld\n", v1?(k+1)*v1:v*(k+1)+n-l+1-(p&&p<n));
	}
	return 0;
}