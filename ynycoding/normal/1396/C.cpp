#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f3f3f3f
#define ll long long
const int N=1000005;
int n, a[N], r1, r2, r3, d;
ll f[N][3];
inline void gmn(ll &x, ll a) { x=std::min(x, a); }
int main()
{
	scanf("%d%d%d%d%d", &n, &r1, &r2, &r3, &d);
	r1=std::min(r1, r3);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	f[0][1]=f[0][2]=INF;
	for(int i=1; i<=n; ++i)
	{
		ll s1=1ll*r1*a[i]+r3, s2=std::min(1ll*r1*(a[i]+2), 1ll*r2+std::min(r1, r2)), s3=std::min(s1, s2);
		f[i][0]=std::min(f[i-1][0]+s1, f[i-1][1]+s3)+d;
		f[i][1]=std::min(f[i-1][0]+(i==n?s1:s3), f[i-1][1]+s3)+3ll*d;
		f[i][2]=std::min({f[i-1][0]+(i==n?s1:s3), f[i-1][1]+s3, f[i-1][2]+(i==n?s1:s3)})+2ll*d;
	}
	printf("%lld\n", std::min({f[n][0]-d, f[n][1]-3ll*d, f[n][2]-2ll*d}));
	return 0;
}