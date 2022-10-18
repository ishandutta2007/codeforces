#include <cstdio>
#include <cmath>
#include <algorithm>
#define bel(x) (((x)+blc-1)/blc)
const int N=200005, B=505, lim=500, blc=500;
int n, m, x[N], y[N], is[N], t[N];
int sum[B][B];
int tag[B], val[N];
inline void add(int x, int v)
{
	tag[bel(x)]+=v, val[x]+=v;
}
inline int ask(int x)
{
	int ret=0;
	for(int i=1; i<bel(x); ++i) ret+=tag[i];
	for(int i=(bel(x)-1)*blc+1; i<=x; ++i) ret+=val[i];
	return ret;
}
inline void solve(int x)
{
	int ans=0;
	for(int i=1; i<=lim; ++i)
		ans+=sum[i][(x-1)%i+1];
	printf("%d\n", ans+ask(x));
}
inline void radd(int u, int v, int t)
{
	is[u]+=v;
	if(x[u]+y[u]>lim)
	{
		int cur=t-1;
		while(cur+x[u]<m)
		{
			add(cur+x[u]+1, v);
			if(cur+x[u]+y[u]+1<=m) add(cur+x[u]+y[u]+1, -v);
			cur+=x[u]+y[u];
		}
	}
	else
	{
		for(int i=x[u]+1; i<=x[u]+y[u]; ++i) sum[x[u]+y[u]][(i+t-2)%(x[u]+y[u])+1]+=v;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i);
	for(int i=1, op, k; i<=m; ++i)
	{
		scanf("%d%d", &op, &k);
		if(op==1) radd(k, 1, i), t[k]=i;
		else radd(k, -1, t[k]);
		solve(i);
	}
	return 0;
}