# include <cstdio>
# include <cstring>
# include <vector>
using namespace std;
const int mod = 1e9 + 7;
const int MN = 1e5 + 44;
long long fac[MN], fin[MN];
vector <pair <int, int> > queries[MN];
# define nr first
# define len second
long long pow(long long b, int e)
{
	if (e == 0)
		return 1;
	else if (e % 2)
		return pow(b, e - 1) * b % mod;
	else
		return pow(b * b % mod, e / 2);
}
long long bin(int a, int b)
{
	if (b < 0 || b > a)
		return 0;
	else
		return fac[a] * fin[b] % mod * fin[a - b] % mod;
}
char in[MN];
long long ans[MN];
long long val[MN];
int main()
{
	const int A = 26, Ain = pow(A, mod - 2), A1in = pow(A - 1, mod - 2), a1ova = (A - 1ll) * Ain % mod;
// 	printf("%d\n", a1ova * (long long)A % mod);
// 	printf("Ain = %d\n", Ain);
	fac[0] = 1;
	for (int i = 1; i < MN; ++i)
		fac[i] = fac[i - 1] * i % mod;
	fin[MN - 1] = pow(fac[MN - 1], mod - 2);
	for (int i = MN - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1) % mod;
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		for (int k = 0; k <= i; ++k)
// 			printf("%d ", (int) bin(i, k));
// 		printf("\n");
// 	}
	int q, len;
	scanf("%d%s", &q, in);
	len = strlen(in);
	int cou = 0;
	for (int i = 0; i < q; ++i)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			scanf("%s", in);
			len = strlen(in);
		}
		else
		{
			int n;
			scanf("%d", &n);
			queries[len].push_back(make_pair(cou, n));
			cou++;
		}
	}
	for (int p = 0; p < MN; ++p)
		if (queries[p].size())
		{
// 			printf("on plen = %d\n", p);
			long long power = 1;
			val[0] = 0;
			for (int k = 1; k < MN; ++k)
			{
				power = power * a1ova % mod;
// 				if (k < 20)
// 					printf("add bin = %d * pow = %d\n", bin(k, p), power);
				val[k] = (val[k - 1] + bin(k - 1, p - 1) * power) % mod;
			}
			for (auto q : queries[p])
			{
// 				printf("on n = %d nr = %d\n", q.len, q.nr);
				ans[q.nr] = (val[q.len] * pow(A, q.len) % mod * pow(A1in, p)) % mod;
			}
		}
	for (int i = 0; i < cou; ++i)
		printf("%d\n", (int) ans[i]);
}