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

int a[100001];
int b[100001];

int solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
		--b[i];
	}
	ll sum = 0;
	vector <int> v(0);
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < sz(v); ++j)
		{
			if (v[j] == b[i])
			{
				v.erase(v.begin() + j);
				break;
			}
			sum += a[v[j]];
		}
		v.insert(v.begin(), b[i]);
	}
	cout << sum << '\n';
	return 0;
}