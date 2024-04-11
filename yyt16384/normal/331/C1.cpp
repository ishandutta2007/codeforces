#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

typedef std::pair<int, long long> Pil;

long long n;
std::map<Pil, Pil> mp;

void init()
{
	scanf("%"LLFORMAT"d", &n);
}

Pil get_msb(long long x)
{
	long long p = 1;
	while (p <= x / 10) p *= 10;
	return Pil(x / p, x / p * p);
}

Pil f(Pil x)
{
	if (mp.find(x) != mp.end())
		return mp[x];
	if (x.second < 10)
		return mp[x] = Pil(x.second - std::max(x.first, (int)x.second), x.first || x.second);
	Pil t = get_msb(x.second);
	Pil res = f(Pil(std::max(x.first, t.first), x.second - t.second));
	Pil res2 = f(Pil(x.first, t.second + res.first));
	return mp[x] = Pil(res2.first, res.second + res2.second);
}

void solve()
{
	Pil res = f(Pil(0, n));
	printf("%"LLFORMAT"d\n", res.second);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8755.in", "r", stdin);
	freopen("8755.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}