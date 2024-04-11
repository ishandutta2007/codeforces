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

int s[100001];
int deg[100001];
bool used[100001];
queue <int> q;
vector <pair <int, int> > ans;

int solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> deg[i] >> s[i];
		if (deg[i] < 2)
		{
			q.push(i);
			used[i] = true;
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (deg[u] == 0)
			continue;
		--deg[u];
		int v = s[u];
		--deg[v];
		s[v] ^= u;
		ans.push_back({u, v});
		if (deg[v] < 2 && !used[v])
		{
			q.push(v);
			used[v] = true;
		}
	}
	cout << sz(ans) << '\n';
	for (auto e: ans)
		cout << e.first << ' ' << e.second << '\n';
	return 0;
}