#include <cstdio>
#include <vector>
#include <algorithm>
const long long MOD = 1000000007;
std::vector < int > d[1000001];
int N, K, Q;
int m[1000001], pr[1000001], phi[1000001], cnt[1000001], v;
long long fc[200001], fi[200001], CK[200001], O;
void insert(int x)
{
	for (int j : d[x])
	{
		O = (O + phi[j] * (CK[cnt[j] + 1] - CK[cnt[j]] + MOD)) % MOD;
		cnt[j]++;
	}
}
int main()
{
	fc[0] = fi[0] = fi[1] = 1;
	for (int i = 2; i <= 200000; i++)
		fi[i] = (MOD - MOD / i) * fi[MOD % i] % MOD;
	for (int i = 1; i <= 200000; i++)
	{
		fc[i] = fc[i - 1] * i % MOD;
		fi[i] = fi[i - 1] * fi[i] % MOD;
	}
	for (int i = 1; i <= 1000000; i++)
		for (int j = i; j <= 1000000; j += i)
			d[j].push_back(i);
	phi[1] = 1;
	for (int i = 2; i <= 1000000; i++)
	{
		if (!m[i])
		{
			m[i] = pr[++v] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= v && pr[j] * i <= 1000000 && pr[j] <= m[i]; j++)
		{
			m[pr[j] * i] = pr[j];
			phi[pr[j] * i] = phi[i] * (pr[j] - (pr[j] != m[i]));
		}
	}
	scanf("%d%d%d", &N, &K, &Q);
	for (int i = 0; i < K; i++)
		CK[i] = 0;
	for (int i = K; i <= N + Q; i++)
		CK[i] = fc[i] * fi[i - K] % MOD * fi[K] % MOD;
	for (int i = 1, x; i <= N; i++)
	{
		scanf("%d", &x);
		insert(x);
	}
	for (int i = 1, x; i <= Q; i++)
	{
		scanf("%d", &x);
		insert(x);
		printf("%lld\n", O);
	}
}