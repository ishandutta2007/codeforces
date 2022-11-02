#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXR = 3005;
const int MAXC = 3005;
const int MAXS = 18000005;

namespace hash
{

int now;
int a[MAXS];

void reset()
{
	++now;
}

void set(int x)
{
	a[x] = now;
}

bool get(int x)
{
	return a[x] == now;
}

}

struct Neighbors
{
	int n;
	int a[8];

	Neighbors() : n(0) {}
};

int r, c, n, m;
bool a[MAXR][2*MAXC];
int fa[MAXS];
int rank[MAXS];

int getfa(int x)
{
	int root = x;
	while (fa[root] != root)
		root = fa[root];
	while (x != root)
	{
		int tmp = fa[x];
		fa[x] = root;
		x = tmp;
	}
	return root;
}

void merge(int x, int y)
{
	x = getfa(x); y = getfa(y);
	if (x == y) return;
	if (rank[x] < rank[y]) fa[x] = y;
	else if (rank[y] < rank[x]) fa[y] = x;
	else fa[x] = y, ++rank[y];
}

void init()
{
	scanf("%d%d%d", &r, &c, &n);
}

Neighbors get_neighbors(int x)
{
	const int DR[8][2] = {
		{-1, -1}, {-1, 0}, {-1, 1},
		{ 0, -1},          { 0, 1},
		{ 1, -1}, { 1, 0}, { 1, 1},
	};

	hash::reset();
	int ux = x / (2*c);
	int	uy = x % (2*c);

	Neighbors p;
	for (int i = 0; i < 8; ++i)
	{
		int tx = ux + DR[i][0];
		int ty = uy + DR[i][1];
		if (tx >= 0 && tx < r)
		{
			if (ty < 0) ty += 2*c;
			if (ty >= 2*c) ty -= 2*c;
			if (a[tx][ty])
			{
				int y = tx * (2*c) + ty;
				y = getfa(y);
				if (!hash::get(y))
				{
					hash::set(y);
					p.a[p.n++] = y;
				}
			}
		}
	}

	return p;
}

bool check_common(const Neighbors &x, const Neighbors &y)
{
	hash::reset();
	for (int i = 0; i < x.n; ++i)
		hash::set(x.a[i]);
	for (int i = 0; i < y.n; ++i)
		if (hash::get(y.a[i]))
			return true;
	return false;
}

bool has_path(int x, int y)
{
	Neighbors px = get_neighbors(x);
	Neighbors py = get_neighbors(y);
	return check_common(px, py);
}

void add(int x)
{
	Neighbors px = get_neighbors(x);
	for (int i = 0; i < px.n; ++i)
		merge(px.a[i], x);
}

void solve()
{
	if (c == 1)
	{
		printf("0\n");
		return;
	}

	m = 2 * r * c;
	for (int i = 0; i < m; ++i)
	{
		fa[i] = i;
		rank[i] = 0;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		int p1 = x * (2*c) + y;
		int p2 = p1 + c;
		if (!has_path(p1, p2))
		{
			add(p1);
			add(p2);
			++ans;
			a[x][y] = a[x][y+c] = true;
		}
	}

	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8740.in", "r", stdin);
	freopen("8740.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}