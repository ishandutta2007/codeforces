# include <cstdio>
# include <set>
using namespace std;
const int MN = 3e5 + 44;
int a[MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", a + i);
		a[i] ^= 1;
	}
	int res = 0;
	int sum = 0;
	int h = 0;
	int l = 0, r = 0;
	for (int t = 0; t < n; ++t)
	{
		while (sum + a[h] <= k && h < n)
		{
			sum += a[h];
			h++;
		}
		if (h - t > res)
		{
			res = h - t;
			l = t;
			r = h;
		}
		res = max(res, h - t);
		sum -= a[t];
	}
	printf("%d\n", res);
	for (int i = l; i < r; ++i)
		a[i] = 0;
	for (int i = 0; i < n; ++i)
		printf("%d ", 1 - a[i]);
	printf("\n");
}