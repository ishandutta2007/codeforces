#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
	srand(2317);
	cout.precision(10);
	cout.setf(ios::fixed);
	#ifdef LOCAL
	freopen("a.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

ll divide(ll a, ll b)
{
	return (a + b - 1) / b;
}

int solve()
{
	int hy, ay, dy, hm, am, dm;
	ll H, A, D;
	cin >> hy >> ay >> dy >> hm >> am >> dm >> H >> A >> D;
	ll ans = INFL;
	for (int dA = 0; dA <= 300; ++dA)
		for (int dD = 0; dD <= 300; ++dD)
		{
			if (ay + dA <= dm)
				continue;
			if (am <= dy + dD)
			{
				ans = min(ans, dA * A + dD * D);
				continue;
			}
			ll moves2 = divide(hm, ay + dA - dm);
			int lb = -1, rb = 1000000;
			while (lb + 1 < rb)
			{
				int dH = (lb + rb) / 2;
				ll moves1 = divide(hy + dH, am - dy - dD);
				if (moves1 > moves2)
					rb = dH;
				else
					lb = dH;
			}
			int dH = rb;
			ans = min(ans, dA * A + dD * D + dH * H);
		}
	cout << ans << '\n';
	return 0;
}