# include <cstdio>
const int MOD = 1e9 + 7;
long long pow(int b, int e)
{
	if (e == 0)
		return 1;
	else if (e % 2)
		return pow(b, e - 1) * b % MOD;
	long long h = pow(b, e / 2);
	return h * h % MOD;
}
const int MN = 1e6 + 44;
long long f[MN], fin[MN];
long long bin(int a, int b)
{
	return f[a] * fin[b] % MOD * fin[a - b] % MOD;
}
int main()
{
	f[0] = 1;
	for (int i = 1; i < MN; ++i)
		f[i] = f[i - 1] * i % MOD;
	fin[MN - 1] = pow(f[MN - 1], MOD - 2);
	for (int i = MN - 2; i >= 0; --i)
		fin[i] = fin[i + 1] * (i + 1) % MOD;
// 	for (int i = 0; i < 10; ++i)
// 	{
// 		for (int k = 0; k <= i; ++k)
// 			printf("%d ", bin(i, k));
// 		printf("\n");
// 	}
	int n, m;
	scanf("%d%d", &n, &m);
	long long res = 0;
	long long sum = 0;
	for (int k = 0; k <= n; ++k)
	{
// 		printf("k = %d sum = %lld\n", k, sum);
		res = (res + pow(m, k) * (pow (m, n) - sum)) % MOD;
		sum = (sum + bin(n, k) * pow(m - 1, n - k)) % MOD;
	}
	if (res < 0)
		res += MOD;
	printf("%d\n", (int) res);
}