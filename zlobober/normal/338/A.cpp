#include <cstdio>
#include <iostream>
using namespace std;

typedef long long llong;

/*bool can(llong n, llong m, llong k, llong q)
{
	llong f = k * q + k - 1;
	if (f >= m && f <= n)
		return true;
	
}*/

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const llong mod = 1000 * 1000 * 1000 + 9;


llong powmod(llong a, llong b)
{
	if (!b)
		return 1;
	else if (1 ^ b & 1)
		return powmod((a * a) % mod, b / 2);
	else
		return (a * powmod((a * a) % mod, b / 2)) % mod;
}


int main()
{
	llong n, m, k;
	cin >> n >> m >> k;
	int mx = n - n / k;
	int ud;
	int af;
	if (m <= mx)
	{
		ud = 0;
		af = m;
		eprintf("stupid: ud = %d, af = %d\n", ud, af);
	}
	else
	{
		int r = n - m;
		int p = r * k - 1;
		eprintf("r = %d\np = %d\n", r, p);
		ud = (n - p - 1) / k;
		af = m - ud * k;
		eprintf("clever: ud = %d, af = %d\n", ud, af);
	}
	llong res = (((powmod(2, ud + 1) - 2 + mod) * k) % mod + mod + af) % mod;
	cout << res << endl;
	/*llong a = -1, b = n / k + 1;
	while (b - a > 1)
	{
		llong q = (a + b) / 2;
		if (can(n, m, k, q))
			b = q;
		else
			a = q;
	}
	llong ud = b;*/
}