#include <cstdio>
#include <cmath>
#include <numeric>
#include <algorithm>
#define ll long long
const int N=200005;
int T, n;
ll a[N], d, k;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%lld", &n, &k);
		for(int i=1; i<=n; ++i) scanf("%lld", a+i);
		k-=a[1];
		for(int i=n; i; --i) a[i]-=a[1];
		d=0;
		for(int i=1; i<=n; ++i) d=std::__gcd(d, a[i]);
		puts(k%d?"NO":"YES");
	}
	return 0;
}