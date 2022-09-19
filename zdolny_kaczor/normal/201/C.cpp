# include <cstdio>
# include <set>
using namespace std;
const int MN = 1e5 + 44;
long long e[MN], oe[MN], eoe[MN];
int a[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	e[n] = oe[n] = eoe[n] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (a[i] > 1)
			e[i] = e[i + 1] + a[i] / 2 * 2;
		oe[i] = max(e[i], max(e[i + 1], oe[i + 1]) + (a[i] + 1) / 2 * 2 - 1);
		eoe[i] = oe[i];
		if (a[i] > 1)
			eoe[i] = max(eoe[i], eoe[i + 1] + a[i] / 2 * 2);
	}
	long long res = 0;
	for (int i = 0; i < n; ++i)
		res = max(eoe[i], res);
	printf("%I64d\n", res);
}