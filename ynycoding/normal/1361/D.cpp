#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#define x first
#define y second
#define ld double
#define pb push_back
using std::vector;
using std::pair;
const int N=500005;
int n, k, tot;
ld dis[N], sum[N], ans, cur, val[N];
pair<int, int> p[N], lsh[N];
vector<ld> e[N];
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		int d=std::__gcd(std::abs(p[i].x), std::abs(p[i].y));
		dis[i]=std::sqrt(1ll*p[i].x*p[i].x+1ll*p[i].y*p[i].y);
		if(d) p[i].x/=d, p[i].y/=d;
		lsh[i]=p[i];
//		printf("dis %.6lf\n", dis[i]);
	}
	std::sort(lsh+1, lsh+n+1);
	for(int i=1; i<=n; ++i) if(dis[i]>1e-6)
	{
		int t=std::lower_bound(lsh+1, lsh+n+1, p[i])-lsh;
		e[t].pb(dis[i]);
	}
	int s=n-k;
	#define calc(i, j) e[(i)][(j)]*(k-(int)e[i].size()+(j)-((int)e[i].size()-(j)-1))
	#define calc1(i, j) e[(i)][(j)]*(k-1-2*((int)e[i].size()-(j)-1))
	for(int i=1; i<=n; ++i)
	{
		std::sort(e[i].begin(), e[i].end());
		for(int j=0; j<e[i].size(); ++j)
		{
			sum[i]+=calc(i, j);
		}
		cur+=sum[i];
	}
	if(k==n)
	{
		printf("%.6lf\n", cur);
		return 0;
	}
	for(int i=1; i<=n; ++i) if(s<=e[i].size())
	{
		ld ad=0;
		int tot=e[i].size();
		for(int j=0; j<s; ++j) ad-=calc(i, j);
		ans=std::max(ans, cur+ad);
		for(int j=s; j<e[i].size(); ++j)
		{
			ad-=calc(i, j);
			ad+=e[i][j-s]*((n-tot)+j-s-(tot-j-1));
			ans=std::max(ans, cur+ad);
		}
	}
	cur=0;
	e[0].pb(0);
	for(int i=0; i<=n; ++i)
	{
		for(int j=0; j<e[i].size(); ++j) val[++tot]=calc1(i, j);
	}
	std::sort(val+1, val+tot+1, [] (ld x, ld y) { return x>y; } );
	for(int i=1; i<=k; ++i) cur+=val[i];
	printf("%.6lf\n", std::max(ans, cur));
	return 0;
}