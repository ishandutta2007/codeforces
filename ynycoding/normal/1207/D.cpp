#include <cstdio>
#include <vector>
#include <algorithm>
#define MAXN 300005
#define mp std::make_pair
#define ll long long
#define x first
#define y second
#define MOD 998244353
using std::pair;
ll n, fac[MAXN], inv[MAXN], ans, inter=1, l=1, r=1;
pair<ll, ll> a[MAXN];
bool cmp(pair<ll, ll> a, pair<ll, ll> b) { return a.y<b.y; }
int main()
{
	scanf("%d", &n);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(int i=2; i<=n; ++i) fac[i]=(ll)fac[i-1]*i%MOD, inv[i]=(MOD-(ll)inv[MOD%i]*(MOD/i)%MOD);
	for(int i=1; i<=n; ++i) inv[i]=(ll)inv[i-1]*inv[i]%MOD;
	for(int i=1; i<=n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
	std::sort(a+1, a+n+1);
//	for(int i=1; i<=n; ++i) printf("%d %d\n", a[i].x, a[i].y);
	for(int i=2; i<=n; ++i) if(a[i-1].y>a[i].y) inter=0;//, puts("fa");
	if(inter)
	{
		for(int i=1, rr; i<=n; i=rr+1)
		{
			rr=i;
			while(rr<n&&a[rr+1].y==a[i].y&&a[rr+1].x==a[i].x) ++rr;
			inter=(ll)inter*fac[rr-i+1]%MOD;
//			printf("s %d\n", inter);
		}
	}
	for(int i=1, rr; i<=n; i=rr+1)
	{
		rr=i;
		while(rr<n&&a[rr+1].x==a[i].x) ++rr;
		l=(ll)l*fac[rr-i+1]%MOD;
//		printf("%d %d %d\n", i, rr, r);
	}
	std::sort(a+1, a+n+1, cmp);
//	puts("");
	for(int i=1, rr; i<=n; i=rr+1)
	{
		rr=i;
		while(rr<n&&a[rr+1].y==a[i].y) ++rr;
		r=(ll)r*fac[rr-i+1]%MOD;
//		printf("%d %d %d\n", i, rr, r);
	}
	// printf("%d %d %d\n", l, r, inter);
	printf("%d\n", (((ll)fac[n]-(ll)l-(ll)r+(ll)inter)%MOD+(ll)MOD)%MOD);
	return 0;
}