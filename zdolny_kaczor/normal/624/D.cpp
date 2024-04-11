# include <cstdio>
# include <set>
using namespace std;
int gcd(int x, int y)
{
	if (x == 0)
		return y;
	else
		return gcd(y % x, x);
}
const int MN = 1e6 + 42;
int n, rem, cha;
int a[MN];
pair <int, long long> operator+ (pair <int, long long> a, pair <int, long long> b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}
pair <int, long long> values[MN];
long long check2(int first, int tab[], int len)
{
	if (first == 1)
		return 1LL << 62;
	long long res = 0;
	for (int i = 0; i < len; ++i)
		if (gcd(first, tab [i]) > 1)
			values[i] = make_pair(0, 0LL - rem);
		else if (gcd(first, tab [i] + 1) > 1 || gcd(first, tab [i] - 1) > 1)
		{
			values [i] = make_pair(0, 0LL + cha - rem);
			res += cha;
		}
		else
		{
			values [i] = make_pair(1, 0LL);
			res += rem;
		}
	pair <int, long long> acc = make_pair(0, 0LL);
	pair <int, long long> maxi = make_pair(0, 0LL);
	for (int i = 0; i < len; ++i)
	{
// 		printf ("%d %lld\n", values[i].first, values[i].second);
		acc = acc + values [i];
		acc = max(acc, make_pair(0, 0LL));
		maxi = max(maxi, acc);
	}
// 	printf("max = %d %lld\n", maxi.first, maxi.second);
	res -= maxi.second;
	return res;
}

long long check(int first, int tab[], int len)
{
	long long res = 1ll << 62;
	for (int p = 2; p * p <= first; ++p)
	{
		if (first % p == 0)
			res = min(res, check2(p, tab, len));
		while (first % p == 0)
			first /= p;
	}
	if (first > 1)
		res = min(res, check2(first, tab, len));
	return res;
}
int main()
{
	scanf("%d%d%d", &n, &rem, &cha);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	long long res = 1LL << 62;
	res = min(res, check(a[0], a + 1, n - 1));
	res = min(res, check(a[0] - 1, a + 1, n - 1) + cha);
	res = min(res, check(a[0] + 1, a + 1, n - 1) + cha);
	res = min(res, check(a[n - 1], a, n - 1));
	res = min(res, check(a[n - 1] - 1, a, n - 1) + cha);
	res = min(res, check(a[n - 1] + 1, a, n - 1) + cha);
	printf("%I64d\n", res);
}