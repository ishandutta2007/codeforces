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

const int base = (1 << 18);
int t[base * 2];

int get(int l, int r, int v = 1, int cl = 0, int cr = base)
{
	if (l <= cl && cr <= r)
		return t[v];
	if (r <= cl || cr <= l)
		return 0;
	int cc = (cl + cr) / 2;
	return get(l, r, v * 2, cl, cc) + get(l, r, v * 2 + 1, cc, cr);
}

int get_id(int val, int v = 1, int cl = 0, int cr = base)
{
	assert(t[v] > val);
	if (cl + 1 == cr)
		return cl;
	int cc = (cl + cr) / 2;
	if (t[v * 2] > val)
		return get_id(val, v * 2, cl, cc);
	else
		return get_id(val - t[v * 2], v * 2 + 1, cc, cr);
}

void put(int pos, int val = 1)
{
	int v = pos + base;
	while (v)
	{
		t[v] += val;
		v /= 2;
	}
}

int a[300001];
int b[300001];
int k[300001];

int solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n; ++i)
		scanf("%d", b + i);
	reverse(a, a + n);
	reverse(b, b + n);
	
	for (int i = 0; i < n; ++i)
	{
		k[i] = get(0, a[i]);
		put(a[i]);
	}
	memset(t, 0, sizeof(t));
	for (int i = 0; i < n; ++i)
	{
		k[i] += get(0, b[i]);
		put(b[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		k[i + 1] += k[i] / (i + 1);
		k[i] %= (i + 1);
	}
	reverse(k, k + n);
	for (int i = 0; i < n; ++i)
	{
		int pos = get_id(k[i]);
		cout << pos << ' ';
		put(pos, -1);
	}
	cout << '\n';
	return 0;
}