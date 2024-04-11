#include <cstdio>
#include <algorithm>
#define MAXN 300005
#define ll long long
int n, m, k;
ll a[MAXN], b[MAXN][11], c[MAXN][11], ans;
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<=n; ++i) scanf("%I64d", a+i), a[i]+=a[i-1];
	for(int i=1; i<=n; ++i) c[i/m][i%m]=0x3f3f3f3f3f3f3f;
	c[0][0]=0;
	for(int i=0; i<m; ++i) for(int j=0; j*m+i<=n; ++j) b[j][i]=a[j*m+i]-(ll)k*j, c[j][i]=std::min(j>=1?c[j-1][i]:b[j][i], b[j][i]);
	for(int i=1; i<=n; ++i)
	{
		for(int j=i-1; j>=i-m&&j>=0; --j) ans=std::max(ans, a[i]-(ll)(j/m)*k-k-c[j/m][j%m]);
	}
	printf("%I64d", ans);
	return 0;
}