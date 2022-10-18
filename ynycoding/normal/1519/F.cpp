#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N=8;
int n, m, a[N], b[N], c[N][N], f[5*5*5*5*5*5], g[5*5*5*5*5*5], pw[7];
int ret, x[N], *w;
inline void gmn(int &x, int a) { x=std::min(x, a); }
void tr(int u, int s, int cur, int cw)
{
	if(u>m)
	{
		if(!s) gmn(ret, f[cur]+cw);
		return;
	}
	for(int i=(u==m?s:0); i<=std::min(s, x[u]); ++i)
		tr(u+1, s-i, cur+pw[u-1]*(x[u]-i), cw+(i?w[u]:0));
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=m; ++i) scanf("%d", b+i);
	for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j) scanf("%d", c[i]+j);
	pw[0]=1;
	for(int i=1; i<=m; ++i) pw[i]=(b[i]+1)*pw[i-1];
	std::fill(f+1, f+pw[m], INF);
	for(int i=1; i<=n; ++i)
	{
		w=c[i];
		for(int s=0; s<pw[m]; ++s)
		{
			int v=s;
			for(int i=m; i; --i) x[i]=v/pw[i-1], v%=pw[i-1];
			ret=INF;
			tr(1, a[i], 0, 0);
			g[s]=ret;
		}
		std::copy(g, g+pw[m], f);
	}
	int ans=INF;
	for(int s=0; s<pw[m]; ++s) gmn(ans, f[s]);
	printf("%d\n", ans==INF?-1:ans);
	return 0;
}