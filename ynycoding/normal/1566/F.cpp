#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f
using std::vector;
const int N=200005;
int T, n, m, id[N], l[N], r[N], top, al[N], ar[N];
int a[N];
ll f[N][2];
inline void gmn(ll &x, ll a) { x=std::min(x, a); }
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &m, &n);
		for(int i=1; i<=m; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; ++i) scanf("%d%d", al+i, ar+i), id[i]=i, f[i][0]=f[i][1]=INF;
		std::sort(id+1, id+n+1, [] (int x, int y) { return ar[x]==ar[y]?al[x]<al[y]:ar[x]<ar[y]; } );
		std::sort(a+1, a+m+1);
		top=0;
		for(int i=1; i<=n; ++i)
		{
			int u=id[i];
			if(!top||al[u]>l[top])
			{
				while(top&&r[top]==ar[u]) --top;
				l[++top]=al[u], r[top]=ar[u];
			}
		}
		n=top;
		int pr=1;
		for(int i=1, j=0; i<=m; ++i)
		{
			while(j<n&&l[j+1]<=a[i]) ++j;
			ll a0=INF, a1=INF;
//			if(j<pr) { continue; }
			for(int t=pr; t<=j+1; ++t)
			{
				ll al=((i>1||t==1)?t>1?std::max(0, l[t-1]-a[i-1]):0:INF);
				ll ar=(t<=j?std::max(0, a[i]-r[t]):0);
				gmn(f[j][0], f[pr-1][1]+al+ar);
				gmn(f[j][0], f[pr-1][0]+2ll*al+ar);
				gmn(f[j][1], f[pr-1][1]+al+2ll*ar);
				gmn(f[j][1], f[pr-1][0]+2ll*al+2ll*ar);
			}
			pr=j+1;
		}
		ll ans=INF;
		if(pr>n) ans=std::min(f[n][0], f[n][1]);
		else
		{
			gmn(ans, f[pr-1][1]+std::max(0, l[n]-a[m]));
			gmn(ans, f[pr-1][0]+2ll*std::max(0, l[n]-a[m]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}