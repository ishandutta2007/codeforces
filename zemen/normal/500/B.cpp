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
	freopen("b.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

int p[501];
string s[501];

int col[501];

int get(int u)
{
	return u == col[u] ? u : col[u] = get(col[u]);
}

void join(int u, int v)
{
	u = get(u), v = get(v);
	if (u == v)
		return;
	col[u] = v;
}

int ans[501];

int solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> p[i], col[i] = i;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (s[i][j] == '1')
				join(i, j);
	for (int i = 0; i < n; ++i)
	{
		if (col[i] != i)
			continue;
		vector <int> v(0);
		for (int j = 0; j < n; ++j)
			if (get(j) == i)
				v.push_back(p[j]);
		sort(v.begin(), v.end());
		int ptr = 0;
		for (int j = 0; j < n; ++j)
			if (get(j) == i)
				ans[j] = v[ptr++];
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}