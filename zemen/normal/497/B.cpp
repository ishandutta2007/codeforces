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

int a[200001];
int id[200001];
int pr[2][200001];
int nx_diff[200001];
vector <int> pos[2];
vector <pair <int, int> > res;

int get(int c, int l, int r)
{
	return pr[c][r] - pr[c][l];
}

int solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		--a[i];
		id[i] = sz(pos[a[i]]);
		pos[a[i]].push_back(i);
	}
	int last[2] = {n, n};
	for (int i = n - 1; i >= 0; --i)
	{
		nx_diff[i] = last[a[i] ^ 1];
		last[a[i]] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		pr[0][i + 1] = pr[0][i];
		pr[1][i + 1] = pr[1][i];
		pr[a[i]][i + 1]++;
	}
	for (int t = 1; t <= n; ++t)
	{
		int x = 0;
		bool fail = false;
		int s[2] = {0, 0};
		while (x < n)
		{
			fail = true;
			for (int i = 0; i < 2; ++i)
			{
				int ind = id[x] + t - 1;
				if (i != a[x])
				{
					if (nx_diff[x] == n)
						continue;
					ind = id[nx_diff[x]] + t - 1;
				}
				if (ind >= sz(pos[i]))
					continue;
				int x2 = pos[i][ind];
				if (get(i ^ 1, x, x2) >= t)
					continue;
				++s[i];
				x = x2 + 1;
				fail = false;
				break;
			}
			if (fail)
				break;
		}
		if (s[a[n - 1]] <= s[a[n - 1] ^ 1])
			fail = true;
		if (!fail)
			res.push_back(make_pair(s[a[n - 1]], t));
	}
	sort(res.begin(), res.end());
	cout << sz(res) << '\n';
	for (auto p: res)
		cout << p.first << ' ' << p.second << '\n';
	return 0;
}