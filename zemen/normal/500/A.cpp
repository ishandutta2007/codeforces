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

int a[1000001];

int solve()
{
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; ++i)
		cin >> a[i];
	int cur = 1;
	while (cur < n && cur != k)
		cur += a[cur];
	if (cur == k)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}