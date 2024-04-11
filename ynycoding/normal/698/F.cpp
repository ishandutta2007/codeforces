#include <cstdio>
#include <random>
#include <algorithm>
#define ull unsigned long long
const int N=1000005, MOD=1000000007;
std::mt19937_64 rnd(114);
int n, p[N], in[N], pr[N], is[N], rw[N], rp[N], cnt[N], top;
int fac[N], tp, ans=1;
ull hs[N], hs1[N], bs[N], a[N], b[N];
void init(int n)
{
	rw[1]=1;
	for(int i=2; i<=n; ++i)
	{
		if(!is[i]) rw[i]=i, pr[++top]=i, rp[i]=i;
		for(int j=1; j<=top&&i*pr[j]<=n; ++j)
		{
			int x=i*pr[j];
			is[x]=1;
//			printf("rx %d\n", x);
			if(i%pr[j]==0) { rw[x]=rw[i]; break; }
			rw[x]=rw[i]*pr[j];
			rp[x]=pr[j];
		}
	}
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD;
}
int main()
{
	scanf("%d", &n);
	init(n);
	for(int i=1; i<=n; ++i) scanf("%d", p+i);
	for(int i=0; i<=n; ++i) bs[i]=rnd();
	for(int i=1; i<=n; ++i) if(!is[i])
		hs[i]^=bs[i==1?0:n/i-1];
	std::copy(hs+1, hs+n+1, hs1+1);
	for(int i=1; i<=n; ++i) ++cnt[rw[i]];
	for(int i=1; i<=n; ++i) if(p[i]>0)
	{
		--cnt[rw[i]];
		ull v=rnd();
		int x=rw[i];
		if(x==1) hs[1]^=v;
		while(x>1)
		{
			hs[rp[x]]^=v;
			x/=rp[x];
		}
		x=rw[p[i]];
		if(x==1) hs1[1]^=v;
		while(x>1)
		{
			hs1[rp[x]]^=v;
			x/=rp[x];
		}
	}
	for(int i=1; i<=n; ++i) if(!is[i])
		a[++tp]=hs[i], b[tp]=hs1[i];
	std::sort(a+1, a+tp+1);
	std::sort(b+1, b+tp+1);
	for(int i=1; i<=n; ++i) if(a[i]!=b[i]) return puts("0"), 0;
	for(int i=1; i<=n; ++i) ans=1ll*ans*fac[cnt[i]]%MOD;
	for(int l=1, r; l<=tp; l=r+1)
	{
		r=l;
		while(r<tp&&a[r+1]==a[l]) ++r;
		ans=1ll*ans*fac[r-l+1]%MOD;
	}
	printf("%d\n", ans);
	return 0;
}