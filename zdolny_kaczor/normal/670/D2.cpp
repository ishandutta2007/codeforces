# include <cstdio>
# include <set>
using namespace std;
const int MN = 1e5 + 44;
int a[MN], b[MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	long long low = 0, high = 3e9 + 44, ans = 0;
	while (low <= high)
	{
		long long med = (low + high) / 2;
		long long needed = 0;
		for (int i = 0; i < n && needed <= k; ++i)
			needed += max(0ll, med * (long long)a[i] - b[i]);
		if (needed > k)
			high = med - 1;
		else
		{
			ans = med;
			low = med + 1;
		}
	}
	printf("%I64d\n", ans);
}