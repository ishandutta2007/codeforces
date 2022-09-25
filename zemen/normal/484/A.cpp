#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;

#define NAME "a"

bool dig(ll a, int d) {
	return a & (1ll << d);
}

ll calc(ll l, ll r)
{
	if (l == r)
		return l;
	ll res = 0;
	for (int q = 62; q >= 0; --q)
	{
		if (dig(l, q) != dig(r, q))
		{
			res += (1ll << q) - 1;
			bool ok = true;
			for (int i = q; i >= 0; --i)
				if (!dig(r, i))
					ok = false;
			if (ok)
				res += (1ll << q);
			return res;
		} else {
			if (dig(l, q))
				res += (1ll << q);
		}
	}
	return res;
}

int main()
{
	#ifdef LOCAL
	freopen(NAME ".in", "r", stdin);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll l, r;
		cin >> l >> r;
		cout << calc(l, r) << '\n';
	}
}