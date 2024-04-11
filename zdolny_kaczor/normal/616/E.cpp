# include <cstdio>
# include <set>
using namespace std;
const int mod = 1e9 + 7;
const int root = 2e7;
inline long long sumpre(long long n)
{
	n %= mod;
	return (n * (n + 1ll) / 2) % mod;
}
inline long long between(long long a, long long b)
{
// 	printf("between %I64d %I64d\n", a, b);
	if (a <= b)
		return (sumpre(b) - sumpre(a - 1)) % mod;
	else
		return 0;
}
inline int roundup(int a, int b)
{
	return (a + b - 1) / b;
}
int main()
{
	if (root < 1e7)
		printf("wrong root!!!!!!!!\n");
	long long n, m;
	scanf("%I64d%I64d", &n, &m);
	long long res = (m % mod) * (n % mod) % mod;
	for (int k = 1; k <= root; ++k)
	{
// 		printf("in %d\n", k);
		long long betret = between(n / (k + 1) + 1, min(n / k, m));
		res -= k * betret;
		res %= mod;
	}
	for (int i = 1; n / i > root && i <= m; ++i)
	{
// 		printf("add n / %d\n", i);
		res -= i * (n / i);
		res %= mod;
	}
	if (res < 0)
		res += mod;
	printf("%I64d\n", res);
	
	if (root < 1e7)
		printf("wrong root!!!!!!!!\n");
}