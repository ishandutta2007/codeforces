#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
using std::vector;
const int N=305, MOD=1000000007;
inline int mval(int x) { return x>=MOD?x-MOD:x; }
inline int fix(int x) { return x+(x>>31&MOD); }
inline void inc(int &x, int a) { x=mval(x+a); }
inline void dec(int &x, int a) { x=fix(x-a); }
inline int qpow(int x, int p)
{ int ret=1; while(p) { if(p&1) ret=1ll*ret*x%MOD; p>>=1, x=1ll*x*x%MOD; } return ret; }

int n, q, a[N], d[N], vec[N][N<<1], sum[N][N], vsum[N][N], pw[N][1005], ipw[N][1005];
int tr[N][N];
vector<int> c[N];
inline int lowbit(int x) { return x&(-x); }
inline void add(int t, int p, int v) { p=std::max(p, 1); while(p<=n) inc(sum[t][p], v), p+=p&(-p); }
inline int ask(int t, int p) { int ret=0; while(p) inc(ret, sum[t][p]), p-=p&(-p); return ret; }
void gauss(int n, int m, int a[][N<<1])
{
	for(int i=1; i<=n; ++i)
	{
		int cur=0;
		for(int j=i; j<=n; ++j) if(a[j][i]) { cur=j; break; }
		for(int j=i; j<=m; ++j) std::swap(a[i][j], a[cur][j]);
		int iv=qpow(a[i][i], MOD-2);
		for(int j=i; j<=m; ++j) a[i][j]=1ll*a[i][j]*iv%MOD;
		for(int j=1; j<=n; ++j) if(j!=i)
		{
			int mul=a[j][i];
			for(int k=i; k<=m; ++k) dec(a[j][k], 1ll*mul*a[i][k]%MOD);
		}
	}
}
void build(void)
{
	for(int i=n; i; --i)
	{
		if(a[i]>0) d[i]=0;
		else
		{
			d[i]=1001;
			for(int j=i+1; j<=n; ++j) if(tr[i][j])
				d[i]=std::min(d[i], d[j]+1);
		}
	}
	for(int i=1; i<=n; ++i) std::fill(sum[i], sum[i]+n+1, 0);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=n; ++j) if(d[i]<=n)
		{
			inc(sum[j][std::max(1, d[i])], 1ll*fix(a[i])*vec[i][j]%MOD*ipw[j][d[i]]%MOD);
		}
	}
	for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) if(j+lowbit(j)<=n)
		inc(sum[i][j+lowbit(j)], sum[i][j]);
}
inline int query(int k, int l, int r)
{
	int ret=0;
	for(int i=1; i<=n; ++i)
	{
		int s1=ask(i, std::min(k, n));
		if(l<=i&&i<=r&&d[i]>k) inc(ret, fix(a[i]));
		inc(ret, 1ll*s1*pw[i][k]%MOD*(MOD+vsum[i][r]-vsum[i][l-1])%MOD);
	}
	return ret;
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i)
	{
		pw[i][0]=ipw[i][0]=1;
		int iv=qpow(i, MOD-2);
		for(int j=1; j<=1000; ++j)
		{
			pw[i][j]=1ll*pw[i][j-1]*i%MOD;
			ipw[i][j]=1ll*ipw[i][j-1]*iv%MOD;
		}
	}
	for(int i=1, k; i<=n; ++i)
	{
		scanf("%d", &k);
		tr[i][i]=i;
		for(int j=1, x; j<=k; ++j) scanf("%d", &x), tr[i][x]=x;
	}
	for(int i=1; i<=n; ++i)
	{
		int d=i;
		vec[i][i]=1;
		for(int j=i-1; j; --j)
		{
			int res=0;
			for(int t=j+1; t<=n; ++t) if(tr[j][t]) inc(res, 1ll*t*vec[i][t]%MOD);
			vec[i][j]=1ll*res*qpow(i-j, MOD-2)%MOD;
		}
		for(int j=1; j<=n; ++j) vsum[i][j]=mval(vsum[i][j-1]+vec[i][j]);
	}
	for(int i=1; i<=n; ++i) vec[i][i+n]=1;
	gauss(n, n*2, vec);
	for(int i=1; i<=n; ++i) std::copy(vec[i]+n+1, vec[i]+2*n+1, vec[i]+1);
	scanf("%d", &q);
	build();
	for(int i=1, op, x, y, z; i<=q; ++i)
	{
		scanf("%d%d%d", &op, &x, &y);
		if(op==1) scanf("%d", &z), printf("%d\n", query(x, y, z));
		else
		{
			a[x]+=y;
			if(a[x]>0&&a[x]-y<=0) build();
			else
			{
				for(int i=1; i<=n; ++i)
				{
					add(i, d[x], 1ll*y*vec[x][i]%MOD*ipw[i][d[x]]%MOD);
				}
			}
		}
	}
	return 0;
}