#include <cstdio>
#include <algorithm>
const int N=400005, MOD=998244353;
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }
int T, n, m, tot, fac[N], inv[N], pos[N], p[N], sum[N], is[N], x[N];
inline void add(int p, int v) { while(p<=n) sum[p]+=v, p+=p&(-p); }
inline int ask(int p) { int ret=0; while(p) ret+=sum[p], p-=p&(-p); return ret; }
inline int find(int k)
{
	int ret=0;
	for(int i=19; ~i; --i)
	{
		if((ret|(1<<i))<=n&&k>sum[ret|(1<<i)])
			ret|=(1<<i), k-=sum[ret];
	}
	return ret+1;
}
inline void init(int n)
{
	inv[0]=inv[1]=fac[0]=1;
	for(int i=2; i<=n; ++i) inv[i]=MOD-1ll*(MOD/i)*inv[MOD%i]%MOD;
	for(int i=1; i<=n; ++i) fac[i]=1ll*i*fac[i-1]%MOD, inv[i]=1ll*inv[i-1]*inv[i]%MOD;
}
int main()
{
	scanf("%d", &T);
	n=200000;
	for(int i=1; i<=n; ++i) add(i, 1);
	init(2*n);
	while(T--)
	{
		scanf("%d%d", &n, &m);
		tot=0;
		std::fill(pos+1, pos+m+1, 0);
//		std::fill(is+1, is+m+1, 0);
		for(int i=1, x, y; i<=m; ++i)
		{
			scanf("%d%d", &x, &y);
			pos[i]=y;
		}
//		std::fill(sum+1, sum+n+1, 0);
//		for(int i=1; i<=n; ++i) add(i, 1);
		for(int i=m; i; --i)
		{
			p[i]=find(pos[i]);
			add(p[i], -1);
		}
		for(int i=1; i<=m; ++i)
		{
//			printf("p %d %d\n", i, p[i]);
			x[i]=find(pos[i]);
			tot+=!is[x[i]];
			is[x[i]]=1;
			add(p[i], 1);
		}
		for(int i=1; i<=m; ++i) is[x[i]]=0;
//		printf("tot %d\n", tot);
		tot=n-tot-1;
		printf("%d\n", 1ll*fac[n+tot]%MOD*inv[n]%MOD*inv[tot]%MOD);
	}
	return 0;
}