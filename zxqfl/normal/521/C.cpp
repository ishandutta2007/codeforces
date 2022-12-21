#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define foreach(x, C) for (auto& x : (C))
#define ever ;;
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define rfloat(x) scanf("%lf", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef pair<double, double> pd;

ll mpow(int a, int b)
{
	if (b < 0) return 0;
	if (b == 0) return 1;
	if (b % 2) return a * mpow(a, b-1) % MOD;
	ll v = mpow(a, b/2);
	return v * v % MOD;
}

ll fact[100010];
ll ifact[100010];

ll C(int n, int k)
{
	if (k < 0 || k > n) return 0;
	return fact[n] * ifact[k] % MOD * ifact[n-k] % MOD;
}

int main()
{
	fact[0] = 1;
	jjs(i, 1, 100010) fact[i] = fact[i-1] * i % MOD;
	ji(100010) ifact[i] = mpow(fact[i], MOD-2);
	int N;
	int K;
	rint(N); rint(K);
	char str[100010];
	scanf("%s", str);
	ll ans = 0;
	ll total = 0;
	for (int i = N-1; i >= 0; i--)
	{
		total += C(i, K-1) * mpow(10, N-i-2) % MOD;
		total %= MOD;
		ll thisOnly = C(i, K) * mpow(10, N-i-1) % MOD;
		// printf("C=%lld pow=%lld\n", C(i, K-1), mpow(10, N-i-1));
		// printf("%c total=%lld\n", str[i], total);
		ans += (total + thisOnly) % MOD * (str[i] - '0');
		ans %= MOD;
	}
	printf("%lld\n", ans);
}