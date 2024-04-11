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

ll A, B;
// ll arr[2000000];

bool isOk(ll l, ll r, ll t, ll m)
{
	ll tot = (r + 1) * A + ((r * (r + 1)) / 2) * B;
	l--;
	tot -= (l + 1) * A + ((l * (l + 1)) / 2) * B;
	// printf("%lld %lld %lld %lld\n", r, t, m, tot);
	return r * B + A <= t && tot <= t * m;
}

int main()
{
	rlong(A);
	rlong(B);
	nrlong(n);
	// arr[0] = A;
	// for (int i = 1; i < 2000000; i++)
	// 	arr[i] = A + i * B + arr[i-1];
	jk(n)
	{
		nrlong(l);
		nrlong(t);
		nrlong(m);
		l--;
		ll lo = l;
		ll hi = (ll) 1e9;
		while (lo < hi)
		{
			ll mid = (lo + hi + 1) / 2;
			if (isOk(l, mid, t, m))
			{
				lo = mid;
			}
			else
			{
				hi = mid - 1;
			}
		}
		printf("%lld\n", isOk(l, lo, t, m) ? (lo + 1) : (-1));
	}
}