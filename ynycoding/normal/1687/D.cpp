#include <cstdio>
#include <cmath>
#include <algorithm>
#define ll long long
const int N=4000005;
int n, is[N], pr[N], nx[N], mx, mn=0x3f3f3f3f;
int main()
{
	scanf("%d", &n);
	for(int i=1, x; i<=n; ++i) scanf("%d", &x), is[x]=1, mx=std::max(mx, x), mn=std::min(mn, x);
	std::copy(is+mn, is+mx+1, is+1);
	mx-=mn-1;
	std::fill(is+mx+1, is+2*mx+1, 0);
	for(int i=1, x=0; i<=2*mx; ++i)
	{
		x=is[i]?i:x;
		pr[i]=x;
	}
	for(int i=2*mx, x=0; i; --i)
	{
		x=is[i]?i:x;
		nx[i]=x;
	}
	for(int i=1; ; ++i)
	{
		ll lim=1ll*i*i-1;
		int l=std::max(mn-1-lim, 0ll), r=i;
		for(int j=i; 1ll*j*j-lim<=mx; ++j)
		{
			int v=1ll*j*(j+1)-lim;
			if(pr[v]) r=std::min(r, v-pr[v]);
			if(nx[v+1]) l=std::max(1ll*l, 1ll*(j+1)*(j+1)-lim-nx[v+1]);
		}
		if(l<=r) return printf("%lld\n", lim+l-(mn-1)), 0;
	}
	return 0;
}