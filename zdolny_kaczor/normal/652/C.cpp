# include <cstdio>
# include <set>
using namespace std;
const int MN = 3e5 + 44;
int pinv[MN];
int shortest[MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		pinv[x] = i;
	}
	for (int i = 1; i <= n; ++i)
		shortest[i] = MN;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a = pinv[a];
		b = pinv[b];
		if (a > b)
			swap(a, b);
		shortest[a] = min(shortest[a], b);
	}
// 	for (int i = 1; i <= n; ++i)
// 		printf("%d.%d\n", i, shortest[i]);
	long long res = 0;
	int range = n + 1;
	for (int i = n; i > 0; --i)
	{
		range = min(range, shortest[i]);
		res += range - i;
	}
	printf("%I64d\n", res);
}