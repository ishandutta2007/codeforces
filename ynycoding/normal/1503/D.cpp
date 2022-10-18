#include <cstdio>
#include <set>
#include <algorithm>
#define INF 0x3f3f3f3f
using std::set;
const int N=400005;
int n, a[N], b[N], bel[N], mn, lim, cur0, cur1;
int f[N], g[N], mx0, mx1;
inline void gmx(int &x, int a) { x=std::max(x, a); }
set<int> A, B;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", a+i, b+i), bel[std::min(a[i], b[i])]=i;
	for(int i=1; i<=n; ++i) if(!bel[i]) return puts("-1"), 0;
	lim=n, mn=n;
	for(int i=1; i<=n; ++i)
	{
		int u=bel[i], v=std::max(a[u], b[u])-n;
		if(v<=mn)
		{
			f[mn]=mx1+cur1-cur0;
			g[mn]=mx0+cur0-cur1;
			gmx(mx0, f[mn]);
			gmx(mx1, g[mn]);
			A.insert(mn), B.insert(mn);
			mn=v;
			if(v+n==a[u]) ++cur0;
			if(v+n==b[u]) ++cur1;
		}
		else
		{
			if(lim<v) return puts("-1"), 0;
			mx0=mx1=-INF;
			while(!A.empty()&&*A.rbegin()>=v)
			{
				gmx(mx0, f[*A.rbegin()]);
				A.erase(prev(A.end()));
			}
			while(!B.empty()&&*B.rbegin()>=v)
			{
				gmx(mx1, g[*B.rbegin()]);
				B.erase(prev(B.end()));
			}
			A.clear(), B.clear();
			f[v]=mx0, g[v]=mx1;
			A.insert(v);
			B.insert(v);
			if(v+n==a[u]) ++cur1;
			if(v+n==b[u]) ++cur0;
			lim=v;
		}
	}
	printf("%d\n", n-std::max(mx0+cur0, mx1+cur1));
	return 0;
}