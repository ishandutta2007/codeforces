#include <cstdio>
#include <algorithm>
const int N=2105;
int n, m, l[N<<1], s[N<<1], mx[N<<1], c[N<<1], f[N][N], ans;
inline void upt(int &x, int a) { x=std::max(x, a); }
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", l+i);
	for(int i=1; i<=n; ++i) scanf("%d", s+i);
	for(int i=1; i<=n+m; ++i) scanf("%d", c+i);
	for(int i=0; i<=m; ++i) std::fill(f[i]+1, f[i]+n+1, -0x3f3f3f3f);
	std::reverse(l+1, l+n+1);
	std::reverse(s+1, s+n+1);
	int lm=0;
	while((1<<lm)<n) ++lm;
	for(int i=1; i<=n; ++i)
	{
		std::fill(mx, mx+n+lm+2, -0x3f3f3f3f);
		for(int j=i-1; ~j; --j) if(f[l[i]][j]>=-0x3f3f3f)
		{
			int v=f[l[i]][j]+c[l[i]]-s[i];
			int k, t;
			for(k=l[i], t=j+1; t; ++k)
			{
				upt(f[k][t], v);
				t>>=1;
				v+=c[k+1]*t;
			}
			upt(mx[k], v);
		}
		for(int k=0, cmx=-0x3f3f3f3f; k<=n+std::min(lm+1, m); ++k) upt(cmx, mx[k]), upt(f[k][0], cmx);
	}
	for(int i=1; i<=n+std::min(m, lm+1); ++i) upt(ans, f[i][0]);
	printf("%d\n", ans);
	return 0;
}