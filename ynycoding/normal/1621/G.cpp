#include <cstdio>
#include <algorithm>
const int N=200005, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return mval(x+MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int T, n, a[N], cnt[N], lsh[N], f[N], g[N], stk[N], bel[N], pr, ans;
int sum[N];
inline void add(int p, int x) { while(p<=n) inc(sum[p], x), p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) inc(ret, sum[p]), p-=p&(-p); return ret; }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), lsh[i]=a[i];
		std::fill(cnt, cnt+n+1, 0);
		std::sort(lsh+1, lsh+n+1);
		for(int i=n; i; --i)
		{
			int p=std::lower_bound(lsh+1, lsh+n+1, a[i])-lsh;
			a[i]=p+(cnt[p]++);
		}
		std::fill(sum, sum+n+1, 0);
		for(int i=1; i<=n; ++i)
		{
			f[i]=mval(1+ask(a[i]-1));
			add(a[i], f[i]);
		}
		std::fill(sum, sum+n+1, 0);
		ans=0;
		for(int i=n; i; --i)
		{
			g[i]=mval(1+ask(n-a[i]));
			add(n-a[i]+1, g[i]);
			inc(ans, 1ll*f[i]*g[i]%MOD);
		}
		pr=0;
		std::fill(sum, sum+n+1, 0);
		for(int i=n; i; --i) if(a[i]>a[pr])
		{
			std::fill(bel+a[pr]+1, bel+a[i]+1, a[i]);
			pr=i;
		}
		for(int i=n; i; --i)
		{
			g[i]=a[i]==bel[a[i]];
			inc(g[i], fix(ask(n-a[i])-ask(n-bel[a[i]])));
			add(n-a[i]+1, g[i]);
			dec(ans, 1ll*f[i]*g[i]%MOD);
		}
		printf("%d\n", ans);
	}
	return 0;
}