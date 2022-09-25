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
	freopen("f.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

pair <int, int> kn[100001];
int res[100001];

const int base = 1 << 16;
vector <int> tree[base * 2];
vector <pair <int, int> > query[100001];

void put(int l, int r, int val, int v = 1, int cl = 0, int cr = base)
{
	if (l <= cl && cr <= r)
	{
		tree[v].push_back(val);
		return;
	}
	if (r <= cl || cr <= l)
		return;
	int cc = (cl + cr) / 2;
	put(l, r, val, v * 2, cl, cc);
	put(l, r, val, v * 2 + 1, cc, cr);
}

const int bd = 4001;
int ans[20][4005];

void relax(int a[4005], int cost, int h)
{
	//~ cerr << "relaxing " << cost << ' ' << h << '\n';
	for (int i = bd - cost; i >= 0; --i)
		a[i + cost] = max(a[i + cost], a[i] + h);
}

void go(int v = 1, int cl = 0, int cr = base, int lvl = 0)
{
	for (int i = 0; i < sz(tree[v]); ++i)
		relax(ans[lvl], kn[tree[v][i]].first, kn[tree[v][i]].second);
	if (cl + 1 == cr)
	{
		for (int i = 0; i < sz(query[cl]); ++i)
		{
			int b = query[cl][i].first;
			int id = query[cl][i].second;
			res[id] = ans[lvl][b];
		}
		return;
	}
	int cc = (cl + cr) / 2;
	memcpy(ans[lvl + 1], ans[lvl], sizeof(ans[lvl]));
	go(v * 2, cl, cc, lvl + 1);
	memcpy(ans[lvl + 1], ans[lvl], sizeof(ans[lvl]));
	go(v * 2 + 1, cc, cr, lvl + 1);
}

int solve()
{
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; ++i)
	{
		int cost, h, tl;
		cin >> cost >> h >> tl;
		kn[i] = make_pair(cost, h);
		int tr = tl + p;
		put(tl, tr, i);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int t, b;
		cin >> t >> b;
		query[t].push_back(make_pair(b, i));
	}
	go();
	for (int i = 0; i < m; ++i)
		cout << res[i] << '\n';
	return 0;
}