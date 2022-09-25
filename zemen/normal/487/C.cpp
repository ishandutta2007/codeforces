#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();

//~ bool used[200001];

int main()
{
	srand(2317);
	cout.precision(10);
	cout.setf(ios::fixed);
	#ifdef LOCAL
	freopen("c.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

ll mod;

ll binpow(ll a, ll x = mod - 2)
{
	ll res = 1;
	while (x)
	{
		if (x & 1)
		{
			res *= a;
			res %= mod;
		}
		x >>= 1;
		a *= a;
		a %= mod;
	}
	return res;
}

int solve()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "YES\n";
		cout << 1 << '\n';
		return 0;
	}
	if (n == 4)
	{
		cout << "YES\n";
		cout << 1 << '\n' << 3 << '\n' << 2 << '\n' << 4 << '\n';
		return 0;
	}
	bool pr = true;
	for (int d = 2; d < n; ++d)
		if (n % d == 0)
			pr = false;
	if (!pr)
	{
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	mod = n;
	cout << 1 << '\n';
	//~ used[1] = true;
	//~ used[n] = true;
	for (int i = 2; i < n; ++i)
	{
		int k = ((ll(i) * ll(binpow(i - 1))) % mod);
		//~ assert(!used[k]);
		//~ used[k] = true;
		cout << k << '\n';
	}
	cout << n << '\n';
	return 0;
}