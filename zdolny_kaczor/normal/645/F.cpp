# include <cstdio>
# include <vector>
const int MOD = 1e9 + 7;
const int range = 1e6 + 44;
std::vector <int> divs[range];
int weight[range];
long long fac[range], fin[range];
long long pow(int b, int e)
{
	if (e == 0)
		return 1;
	else if (e % 2)
		return pow(b, e - 1) * b % MOD;
	long long h = pow(b, e / 2);
	return h * h % MOD;
}
void init()
{
	for (int i = 1; i < range; ++i)
		for (int k = i; k < range; k += i)
			divs[k].push_back(i);
	for (int i = 1; i < range; ++i)
	{
		weight[i] += i;
		for (int k = i * 2; k < range; k += i)
			weight[k] -= weight[i];
	}
	fac[0] = 1;
	for (int i = 1; i < range; ++i)
		fac[i] = fac[i - 1] * i % MOD;
	fin[range - 1] = pow(fac[range - 1], MOD - 2);
	for (int i = range - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1) % MOD;
}
int n, k, q;
int bin(int a, int b)
{
// 	printf("bin %d %d\n", a, b);
	if (a < b)
		return 0;
	return fac[a] * fin[b] % MOD * fin[a - b] % MOD;
}
int muls[range];
int res;
void add(int x)
{
	for (auto d : divs[x])
	{
// 		printf("add bin (%d %d) * (weight[%d] == %d)\n", muls[d], k - 1, d, weight[d]);
		res += bin(muls[d], k - 1) * (long long)weight[d] % MOD;
		res %= MOD;
		muls[d] ++;
	}
}
int main()
{
	init();
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		for (int k = 0; k <= i; ++k)
// 			printf("%d ", bin(i, k));
// 		printf("\n");
// 	}
// 	for (int i = 0; i < 10; ++i)
// 		printf("%d.%d %d\n", i, fac[i], fin[i]);
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < n + q; ++i)
	{
		int a;
		scanf("%d", &a);
		add(a);
		if (i >= n)
			printf("%d\n", res);
	}
}