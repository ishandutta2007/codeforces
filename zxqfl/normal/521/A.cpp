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

int L;
char str[100010];
int freq[256];

int main()
{
	rint(L);
	scanf("%s", str);
	ji(L) freq[str[i]]++;
	int mx = 0;
	ji(256)
		mx = max(mx, freq[i]);
	int cnt = 0;
	ji(256) if (freq[i] == mx)
		cnt++;
	ll ans = 1;
	ji(L)
	{
		ans *= cnt;
		ans %= MOD;
	}
	printf("%lld\n", ans);
}