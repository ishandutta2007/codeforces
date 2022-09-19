# include <cstdio>
# include <iomanip>
# include <iostream>
int p;
long double pra(int l, int r)
{
	int x = r / p - (l - 1) / p;
	return (long double) x / (r - l + 1);
}
const int MN = 1e5 + 44;
int l[MN], r [MN];
int main()
{
	int n;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", l + i, r + i);
	}
	long double res = 0;
	for (int i = 0; i < n; ++i)
	{
		long double p1 = pra(l[i], r[i]);
		long double p2 = pra(l[(i + 1) % n], r[(i + 1) % n]);
		res += (p1 + p2 - p1 * p2);
	}
	std::cout << std::setprecision (10) << res * 2000 << '\n';
}