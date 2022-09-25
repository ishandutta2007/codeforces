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
	freopen("d.in", "r", stdin);
	#else
	#endif
	int tn = 1;
	for (int i = 0; i < tn; ++i)
		solve();
	#ifdef LOCAL
	cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
	#endif
}

int n, m;
const pair <int, int> FICT = make_pair(-1, -1);

struct Block
{
	pair <int, int> d[12];
	int l, r;
	
	Block()
	{
		l = r = -100;
		for (int i = 0; i < m; ++i)
			d[i] = FICT;
	}
	
	Block(const Block &a, const Block &b)
	{
		if (a.l == -100)
		{
			*this = b;
			return;
		}
		if (b.l == -100)
		{
			*this = a;
			return;
		}
		for (int i = 0; i < m; ++i)
			if (b.d[i].first == a.r)
				d[i] = a.d[b.d[i].second];
			else
				d[i] = b.d[i];
		l = a.l, r = b.r;
	}
	
	Block(char *s, int x)
	{
		l = r = x;
		for (int i = 0; i < m; ++i)
		{
			int u = i, from = -100;
			while (true)
			{
				if (u < 0)
				{
					d[i] = make_pair(x, -1);
					break;
				}
				if (u >= m)
				{
					d[i] = make_pair(x, m);
					break;
				}
				if (s[u] == '^')
				{
					d[i] = make_pair(x - 1, u);
					break;
				}
				if (s[u] == '<')
				{
					if (from == u - 1)
					{
						d[i] = FICT;
						break;
					}
					else
					{
						from = u;
						--u;
						continue;
					}
				}
				if (s[u] == '>')
				{
					if (from == u + 1)
					{
						d[i] = FICT;
						break;
					}
					else
					{
						from = u;
						++u;
						continue;
					}
				}
				assert(false);
			}
		}
	}
	
};

const int base = (1 << 17);
Block t[base * 2];
char a[200001][15];

Block get(int l, int r, int v = 1, int cl = 0, int cr = base)
{
	if (l <= cl && cr <= r)
		return t[v];
	if (r <= cl || cr <= l)
		return Block();
	int cc = (cl + cr) / 2;
	Block bl = get(l, r, v * 2, cl, cc);
	Block br = get(l, r, v * 2 + 1, cc, cr);
	return Block(bl, br);
}

void recalc(int v)
{
	while (v > 1)
	{
		v /= 2;
		t[v] = Block(t[v * 2], t[v * 2 + 1]);
	}
}

int solve()
{
	int q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", a[i]);
		t[i + base] = Block(a[i], i);
	}
	for (int i = base - 1; i > 0; --i)
		t[i] = Block(t[i * 2], t[i * 2 + 1]);
	char tmp[5];
	for (int ii = 0; ii < q; ++ii)
	{
		scanf("%s", tmp);
		if (tmp[0] == 'A')
		{
			int x, y;
			scanf("%d%d", &x, &y);
			--x, --y;
			Block B = get(0, x + 1);
			pair <int, int> res = B.d[y];
			if (res == FICT)
				cout << -1 << ' ' << -1 << '\n';
			else
				cout << res.first + 1 << ' ' << res.second + 1 << '\n';
		}
		else
		{
			int x, y;
			char tmp2[5];
			scanf("%d%d%s", &x, &y, tmp2);
			--x, --y;
			a[x][y] = tmp2[0];
			t[x + base] = Block(a[x], x);
			recalc(x + base);
		}
	}
	return 0;
}