#include <cstdio>
#include <algorithm>
#define ll long long
#define N 200005
int n, a[N], pr[N], fac[N], is[N], mn[N][2], tot[N], top;
inline void gp(int n)
{
	for(int i=2; i<=n; ++i)
	{
		if(!is[i]) pr[++top]=i, fac[i]=i;
		for(int j=1; j<=top&&pr[j]*i<=n; ++j)
		{
			fac[i*pr[j]]=pr[j], is[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
}
inline int gcd(int a, int b) { while(b) a%=b, std::swap(a, b); return a; }
int main()
{
	scanf("%d", &n);
	gp(200000);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=200000; ++i) mn[i][0]=mn[i][1]=0x3f3f3f3f;
	for(int i=1; i<=n; ++i)
	{
		while(a[i]>1)
		{
			int t=fac[a[i]], cnt=0;
			while(fac[a[i]]==t) a[i]/=t, ++cnt;
			if(cnt<mn[t][0]) mn[t][1]=mn[t][0], mn[t][0]=cnt;
			else if(cnt<mn[t][1]) mn[t][1]=cnt;
			++tot[t];
		}
	}
	ll ans=1;
	for(int i=1; i<=200000; ++i) if(tot[i]==n) while(mn[i][1]--) ans*=i; else if(tot[i]==n-1) while(mn[i][0]--) ans*=i;
	printf("%lld\n", ans);
	return 0;
}