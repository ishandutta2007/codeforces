# include <cstdio>
# include <vector>
using namespace std;
const int MN = 5e5 + 44;
const int MP = 5e5 + 44;
int div[MP];
int mi[MP];//troch oszukane mi()
void sieve()
{
	mi[1] = 1;
	for (int p = 2; p < MP; ++p)
		if (div[p] == 0)
			for (int x = p; x < MP; x += p)
			{
				mi[x] = - mi[x / p];
				div[x] = p;
			}
}
vector <int> primes;
void find_divs(int x, vector <int> * res)
{
	primes.clear();
	while (x > 1)
	{
		int p = div[x];
		while (x % p == 0)
			x /= p;
		primes.push_back(p);
	}
	int l = primes.size();
	for (int mask = 0; mask < (1 << l); ++mask)
	{
		int add = 1;
		for (int i = 0; i < l; ++i)
			if (mask & (1 << i))
				add *= primes[i];
		res -> push_back(add);
	}
}
long long bin(int n)
{
	return n * (n - 1ll) / 2;
}
long long res = 0;
int cou[MP];
vector <int> splits[MN];
void include (int nr, int sign)
{
	for (auto x : splits[nr])
		res += mi[x] * bin(cou[x]) * sign;
}
void edit(int nr, int sign)
{
	for (auto x : splits[nr])
		cou[x] += sign;
}
bool is[MN];
int main()
{
	sieve();
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		find_divs(a, &splits[i]);
	}
	while (q--)
	{
		int x;
		scanf("%d", &x);
		include (x, -1);
		if (is[x])
		{
			is[x] = false;
			edit(x, -1);
		}
		else
		{
			is[x] = true;
			edit(x, 1);
		}
		include(x, 1);
		printf("%I64d\n", res);
	}
}