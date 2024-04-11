#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rg register
#define fu(i, a, b) for(rg int i = a; i <= b; ++i)
#define fd(i, a, b) for(rg int i = a; i >= b; --i)

const int N = 300005;
int n;
ll a[N][2], s2[N][2], s3[N][2], s1[N][2], cur, ans;

int main() {
	scanf("%d", &n);
	fu(j, 0, 1) fu(i, 1, n) scanf("%lld", &a[i][j]);
	fd(i, n, 1) fu(j, 0, 1) s1[i][j] = s1[i + 1][j] + a[i][j], s2[i][j] = s2[i + 1][j] + s1[i][j], s3[i][j] = s3[i + 1][j] + (n - i + 1) * a[i][j];
	fu(i, 0, n) cur += (a[i][0] + a[i][1]) * ((i - 1) << 1) + a[i][i % 2], ans = max(ans, cur + ((i << 1) - 1) * s1[i + 1][i % 2] + s2[i + 1][i % 2] + (n - 1 + i) * s1[i + 1][1 - i % 2] + s3[i + 1][1 - i % 2]);
	printf("%lld\n", ans);
}