# include <cstdio>
# include <set>
using namespace std;
const int MN = 2e3 + 44;
const long long inf = 1ll << 60;
long long mincost[MN][MN];
int t[MN], c[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", t + i, c + i);
	for (int i = 1; i <= n; ++i)
		mincost[0][i] = inf;
	for (int i = 0; i < n; ++i)
		for (int k = 0; k <= n; ++k)
			mincost[i + 1][k] = min(mincost[i][k], mincost[i][max(0, k - t[i] - 1)] + c[i]);
	printf("%I64d\n", mincost[n][n]);
}