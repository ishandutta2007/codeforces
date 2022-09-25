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

int a[100001];

const int base = (1 << 17);
int t[base * 2];

int get(int l, int r, int v = 1, int cl = 0, int cr = base)
{
	if (l >= r)
		return INF;
	if (l <= cl && cr <= r)
		return t[v];
	if (r <= cl || cr <= l)
		return INF;
	int cc = (cl + cr) / 2;
	return min(get(l, r, v * 2, cl, cc), get(l, r, v * 2 + 1, cc, cr));
}

void put(int v, int val)
{
	v += base;
	t[v] = val;
	while (v > 1)
	{
		v /= 2;
		t[v] = min(t[v * 2], t[v * 2 + 1]);
	}
}

int bd[100001];
multiset <int> values;

int solve()
{
	int n, diff, len;
	cin >> n >> diff >> len;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int lb = 0;
	for (int i = 0; i < n; ++i)
	{
		values.insert(a[i]);
		while (abs(*values.begin() - a[i]) > diff || abs(*values.rbegin() - a[i]) > diff)
		{
			values.erase(values.find(a[lb]));
			++lb;
		}
		bd[i] = lb;
	}
	for (int i = 0; i < 2 * base; ++i)
		t[i] = INF;
	put(0, 0);
	for (int i = 0; i < n; ++i)
	{
		int l = bd[i];
		int r = i - len + 1;
		int ans = min(INF, get(l, r + 1) + 1);
		put(i + 1, ans);
	}
	cout << (get(n, n + 1) != INF ? get(n, n + 1) : -1) << '\n';
	return 0;
}