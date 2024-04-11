#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define sz size()
#define pb push_back
#define clr(x) memset(x, 0, sizeof(x))
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define For(i, st, en) for(int i = (st); i <= (int)(en); i++)
#define Ford(i, st, en) for(int i = (st); i >= (int)(en); i--)

typedef long long i64;
typedef vector < int > VI;

#define BASE 1000000000
#define LEN 16

int n;
VI a[1024];
VI a1[1024];
int d[12][1024][LEN];
int t[1024][LEN];
int c[1024];
bool u[1024];

void tolong(int *a, int k)
{
	memset(a, 0, LEN * sizeof(a[0]));
	do
	{
		a[++a[0]] = k % BASE;
		k /= BASE;
	}
	while (k);
}

void multak(int *a, int k)
{
	i64 j = 0;
	For(i, 1, a[0])
	{
		j += (i64)a[i] * k;
		a[i] = j % BASE;
		j /= BASE;
	}
	if (j) a[++a[0]] = j;
	while (a[0] > 1 && !a[a[0]]) a[0]--;
}

void multab(int *a, int *b)
{
	int c[LEN];
	clr(c);
	For(i, 1, a[0])
	{
		For(j, 1, b[0])
		{
			i64 t = c[i+j-1] + (i64)a[i] * b[j];
			c[i+j-1] = t % BASE;
			c[i+j] += t / BASE;
		}
	}
	c[0] = a[0] + b[0];
	memcpy(a, c, sizeof(c));
	while (a[0] > 1 && !a[a[0]]) a[0]--;
}

bool lessab(int *a, int *b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	Ford(i, a[0], 1)
	{
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

int dfs1(int k)
{
	u[k] = true;
	c[k] = 1;
	forn(i1, a1[k].sz)
	{
		int i = a1[k][i1];
		if (!u[i])
		{
			a[k].pb(i);
			c[k] += dfs1(i);
		}
	}
	return c[k];
}

void writelong(int *a)
{
	printf("%d", a[a[0]]);
	Ford(i, a[0]-1, 1)
	{
		printf("%09d", a[i]);
	}
	puts("");
}

bool cmp(int p1, int p2)
{
	return c[p1] > c[p2];
}

void dfs(int k, int h)
{
	clr(d[h]);
	if (!a[k].sz)
	{
		tolong(d[h][0], 1);
		tolong(d[h][1], 1);
		return;
	}

	dfs(a[k][0], h);
	Ford(i, c[a[k][0]], 0)
	{
		memcpy(d[h][i+1], d[h][i], sizeof(d[h][i]));
	}
	tolong(d[h][0], 0);
	int s = c[a[k][0]];

	For(i1, 1, a[k].sz-1)
	{
		int i = a[k][i1];
		dfs(i, h+1);
		clr(t);
		For(j, 1, s + 1)
		{
			int tmp[LEN];
			memcpy(tmp, d[h][j], sizeof(tmp));
			multab(tmp, d[h+1][0]);
			if (lessab(t[j], tmp))
			{
				memcpy(t[j], tmp, sizeof(tmp));
			}
			For(l, 1, c[i])
			{
				memcpy(tmp, d[h][j], sizeof(tmp));
				multab(tmp, d[h+1][l]);
				if (lessab(t[j + l], tmp))
				{
					memcpy(t[j + l], tmp, sizeof(tmp));
				}
			}
		}
		memcpy(d[h], t, sizeof(t));
		s += c[i];
	}

	For(i, 1, s+1)
	{
		int tmp[LEN];
		memcpy(tmp, d[h][i], sizeof(tmp));
		multak(tmp, i);
		if (lessab(d[h][0], tmp))
		{
			memcpy(d[h][0], tmp, sizeof(tmp));
		}
	}
}

int main()
{
#ifdef ROOM_311
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	scanf("%d", &n);
	forn(i, n-1)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		a1[x].pb(y);
		a1[y].pb(x);
	}

	clr(u);
	dfs1(0);

	forn(i, n)
	{
		sort(a[i].begin(), a[i].end(), cmp);
	}

	dfs(0, 0);

	writelong(d[0][0]);

	return 0;
}