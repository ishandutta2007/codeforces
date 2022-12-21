#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define ever ;;
#define foreach(x, C) for (auto& x : (C))
#define INF ((int) 1e9+10)
#define LINF ((ll) 1e16)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define nrint(x) int x; rint(x);
#define nrlong(x) long long x; rlong(x);
#define rfloat(x) scanf("%lf", &(x))

const int MOD = 1000000007;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N;
int arr[2000];
int restrictions;
bool inArr[2000];
ll fact[2010];
ll C[2010][2010];

int main()
{
	rint(N);
	ji(N) rint(arr[i]);
	ji(N) arr[i]--;
	ji(N) if (arr[i] >= 0) inArr[arr[i]] = true;
	ji(N) if (!inArr[i] && arr[i] < 0)
		restrictions++;
	int tot = 0;
	ji(N) tot += arr[i] < 0;
	
	jij(2010, 2010)
	{
		if (j == 0)
			C[i][j] = 1;
		else if (j > i)
			C[i][j] = 0;
		else
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
	}
	fact[0] = 1;
	jjs(i, 1, 2010) fact[i] = fact[i-1] * i % MOD;

	ll ans = 0;
	for (int wrong = 0; wrong <= restrictions; wrong++)
	{
		ll v = C[restrictions][wrong] * fact[tot - wrong] % MOD;
		if (wrong % 2)
			ans -= v;
		else
			ans += v;
		ans += MOD;
		ans %= MOD;
	}
	printf("%lld\n", ans);
}