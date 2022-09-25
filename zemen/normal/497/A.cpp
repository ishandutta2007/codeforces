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

char a[1005][1005];
bool ok[1005];

int solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%s", a[i]);
	int res = 0;
	for (int i = 0; i < m; ++i)
	{
		bool good = true;
		for (int j = 0; j < n - 1; ++j)
			if (!ok[j] && a[j][i] > a[j + 1][i])
				good = false;
		if (!good)
		{
			++res;
			continue;
		}
		for (int j = 0; j < n - 1; ++j)
			ok[j] |= (a[j][i] < a[j + 1][i]);
	}
	cout << res << '\n';
	return 0;
}