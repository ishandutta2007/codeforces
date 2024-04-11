#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXM = 100005;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int x, y, w;
	int w_orig;
	int id;
};

int n, m;
Edge e[MAXM];
bool nosol;
int ansn;
int ans[MAXN];

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		--x; --y;
		e[i].x = x;
		e[i].y = y;
		e[i].w = w;
		e[i].w_orig = w;
		e[i].id = i;
	}
}

void solve()
{
	const int MAXS = 10000005;
	static int all[MAXS][2];
	static int pre[MAXN];
	static int preid[MAXN];
	static int in[MAXN];
	static int id[MAXN];
	static int pos[MAXN];
	static int use[MAXS];
	static int oke[MAXM];
	int oken = 0;
	int nall = m;
	int root = 0;
	for (int i = 0; i < m; ++i)
		if (e[i].x != e[i].y)
			oke[oken++] = i;
	while (true)
	{
		memset(in, INF, n * sizeof(int));
		memset(pos, -1, n * sizeof(int));
		memset(id, -1, n * sizeof(int));
		for (int i = 0; i < oken; ++i)
		{
			int x = oke[i];
			if (e[x].x != e[x].y && e[x].w < in[e[x].y])
			{
				in[e[x].y] = e[x].w;
				pre[e[x].y] = e[x].x;
				preid[e[x].y] = e[x].id;
			}
		}
		in[root] = 0;
		int cn = 0;
		for (int i = 0; i < n; ++i)
		{
			if (in[i] == INF)
			{
				nosol = true;
				return;
			}
			if (i != root)
				++use[preid[i]];
			int x = i;
			while (x != root && pos[x] == -1)
			{
				pos[x] = i;
				x = pre[x];
			}
			if (x != root && id[x] == -1 && pos[x] == i)
			{
				id[x] = cn;
				for (int j = pre[x]; j != x; j = pre[j])
					id[j] = cn;
				++cn;
			}
		}
		if (!cn)
			break;
		for (int i = 0; i < n; ++i)
			if (id[i] == -1)
				id[i] = cn++;
		oken = 0;
		for (int i = 0; i < m; ++i)
		{
			int tmp = preid[e[i].y];
			e[i].w -= in[e[i].y];
			e[i].x = id[e[i].x];
			e[i].y = id[e[i].y];
			if (e[i].x != e[i].y)
			{
				all[nall][0] = e[i].id;
				all[nall][1] = tmp;
				e[i].id = nall++;
				oke[oken++] = i;
			}
		}
		n = cn;
		root = id[root];
	}
	for (int i = nall - 1; i >= m; --i)
		if (use[i])
		{
			++use[all[i][0]];
			--use[all[i][1]];
		}
	for (int i = 0; i < m; ++i)
		if (use[i] && e[i].w_orig)
			ans[ansn++] = i;
}

void output()
{
	if (nosol)
	{
		printf("-1\n");
		return;
	}
	printf("%d\n", ansn);
	for (int i = 0; i < ansn; ++i)
		printf("%d ", ans[i] + 1);
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9197.in", "r", stdin);
	freopen("9197.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	init();
	solve();
	output();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}