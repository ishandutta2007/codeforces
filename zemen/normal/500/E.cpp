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
	freopen("e.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

int p[200002];
int l[200002];

int d[18][200002];
int c[18][200002];

pair <int, int> o[200002];
set <int> S;
int n;

bool cover(int u, int v)
{
	if (u == n)
		return true;
	return p[u] + l[u] >= p[v];
}

int solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", p + i, l + i);
		o[i] = make_pair(l[i] + p[i], i);
	}
	sort(o, o + n);
	reverse(o, o + n);
	for (int i = 0; i < n; ++i)
	{
		int id = o[i].second;
		auto it = S.lower_bound(id);
		if (it != S.end())
		{
			//~ cerr << "next for " << id << " is " << *it << '\n';
			d[0][id] = *it;
			c[0][id] = max(0, p[*it] - p[id] - l[id]);
		}
		else
		{
			d[0][id] = n;
			c[0][id] = 0;
		}
		S.insert(id);
	}
	d[0][n] = n;
	c[0][n] = n;
	for (int deg = 1; deg < 18; ++deg)
		for (int i = 0; i <= n; ++i)
		{
			d[deg][i] = d[deg - 1][d[deg - 1][i]];
			c[deg][i] = c[deg - 1][i] + c[deg - 1][d[deg - 1][i]];
		}
	
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		int res = 0;
		for (int deg = 17; deg >= 0; --deg)
		{
			if (!cover(d[deg][l], r))
			{
				res += c[deg][l];
				l = d[deg][l];
			}
		}
		if (!cover(l, r))
		{
			res += c[0][l];
			l = d[0][l];
		}
		assert(cover(l, r));
		cout << res << '\n';
	}
	
	return 0;
}