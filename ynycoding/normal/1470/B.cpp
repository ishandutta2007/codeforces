#include <cstdio>
#include <algorithm>
const int N=1000005;
int T, n, q, a[N], cnt[N], ans0, ans1;
int pr[N], is[N], fac[N], par[N], mul[N], top;
long long w;
inline void init(int n)
{
	for(int i=2; i<=n; ++i)
	{
		if(!is[i]) pr[++top]=i, fac[i]=i, mul[i]=i, par[i]=1;
		for(int j=1; j<=top&&pr[j]*i<=n; ++j)
		{
			int x=pr[j]*i;
			is[x]=1;
			fac[x]=pr[j];
			if(i%pr[j]==0) { par[x]=par[i]^1, mul[x]=mul[i]*pr[j]; break; }
			par[x]=1;
			mul[x]=pr[j];
		}
	}
}
int main()
{
	init(1000000);
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		ans0=ans1=0;
		for(int i=1, x; i<=n; ++i)
		{
			scanf("%d", &x);
			a[i]=1;
			while(x>1)
			{
				if(par[x]) a[i]*=fac[x];
				x/=mul[x];
			}
			++cnt[a[i]];
			ans0=std::max(ans0, cnt[a[i]]);
		}
		for(int i=1; i<=n; ++i) if(a[i]==1||!(cnt[a[i]]&1))
			ans1+=cnt[a[i]], cnt[a[i]]=0;
		scanf("%d", &q);
		for(int i=1; i<=q; ++i)
		{
			scanf("%lld", &w);
			if(!w) printf("%d\n", ans0);
			else printf("%d\n", std::max(ans0, ans1));
		}
		for(int i=1; i<=n; ++i) cnt[a[i]]=0;
	}
	return 0;
}