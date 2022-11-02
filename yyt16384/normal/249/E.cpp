#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const long long MOD = 10000000000LL;
const long long MOD2 = 36 * MOD;
const long long MOD3 = 6 * 100000;

int x1, y1, x2, y2;

void init()
{
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
}

long long mulmod(long long x, long long y)
{
	long long a1 = x / MOD3;
	long long a2 = x % MOD3;
	long long b1 = y / MOD3;
	long long b2 = y % MOD3;
	long long s = ((a1 * b2 + a2 * b1) * MOD3 + a2 * b2) % MOD2;
	return s;
}

long long work(long long x, long long y)
{
	if (x >= y)
	{
		long long tx2 = mulmod(x, x);
		long long part1 = x * 4 % MOD2;
		long long part2 = tx2 * 3 % MOD2;
		long long part3 = mulmod(x, tx2) * 2 % MOD2;
		long long part4 = -y;
		long long part5 = -mulmod(x, y) * 3 % MOD2;
		long long part6 = mulmod(y, mulmod(y, y));
		long long ss = ((part1 + part2 + part3 + part4 + part5 + part6) % MOD2 + MOD2) % MOD2;
		return mulmod(ss, y) / 6 % MOD;
	}
	else
	{
		long long ty2 = mulmod(y, y);
		long long part1 = y * 4 % MOD2;
		long long part2 = -ty2 * 3 % MOD2;
		long long part3 = mulmod(y, ty2) * 2 % MOD2;
		long long part4 = -x;
		long long part5 = mulmod(y, x) * 3 % MOD2;
		long long part6 = mulmod(x, mulmod(x, x));
		long long ss = ((part1 + part2 + part3 + part4 + part5 + part6) % MOD2 + MOD2) % MOD2;
		return mulmod(ss, x) / 6 % MOD;
	}
}

long double work2(long double x, long double y)
{
	if (x >= y)
	{
		long double part1 = 4*x;
		long double part2 = 3*x*x;
		long double part3 = 2*x*x*x;
		long double part4 = -y;
		long double part5 = -3*x*y;
		long double part6 = y*y*y;
		return (part1 + part2 + part3 + part4 + part5 + part6) * y / 6;
	}
	else
	{
		long double part1 = 4*y;
		long double part2 = -3*y*y;
		long double part3 = 2*y*y*y;
		long double part4 = -x;
		long double part5 = 3*y*x;
		long double part6 = x*x*x;
		return (part1 + part2 + part3 + part4 + part5 + part6) * x / 6;
	}
}

void solve()
{
	--x1; --y1;
	long long ss = (work(x2, y2) - work(x1, y2) - work(x2, y1) + work(x1, y1) + 2 * MOD) % MOD;
	long double ss2 = work2(x2, y2) - work2(x1, y2) - work2(x2, y1) + work2(x1, y1);
	if (ss2 < 2 * MOD && ss2 <= ss + MOD / 2)
		printf("%"LLFORMAT"d\n", ss);
	else
		printf("...%010"LLFORMAT"d\n", ss);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9170.in", "r", stdin);
	freopen("9170.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--)
	{
		init();
		solve();
	}

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}