#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 205;
const int MAXM = 1005;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int y, w, orig_w;
	int next;
};

int n, m;
Edge edge[2 * MAXM];
int ehead[MAXN];
int edgen;

int dis[MAXN];
bool vis[MAXN];

int fa[MAXN];
int faw[MAXN];

int ans;
int ansp[MAXN];

void addedge(int x, int y, int w)
{
	edge[edgen].y = y;
	edge[edgen].w = edge[edgen].orig_w = w;
	edge[edgen].next = ehead[x];
	ehead[x] = edgen++;
}

void input()
{
	scanf("%d%d", &n, &m);
	memset(ehead, -1, sizeof(ehead));
	for (int i = 0; i < m; ++i)
	{
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		--x; --y;
		addedge(x, y, w);
		addedge(y, x, w);
	}
}

bool BFS(int t, int s)
{
	static int que[MAXN];
	int qb = 0, qe = 1;
	memset(dis, INF, sizeof(dis));
	dis[t] = 0;
	que[0] = t;
	while (qb < qe)
	{
		int x = que[qb++];
		for (int i = ehead[x]; i != -1; i = edge[i].next)
			if (edge[i ^ 1].w && dis[edge[i].y] == INF)
			{
				dis[edge[i].y] = dis[x] + 1;
				que[qe++] = edge[i].y;
			}
	}
	return dis[s] < INF;
}

int DFS(int x, int pre, int t)
{
	if (x == t)
		return pre;
	int sum = 0;
	for (int i = ehead[x]; i != -1; i = edge[i].next)
		if (edge[i].w && dis[x] == dis[edge[i].y] + 1)
		{
			int u = std::min(edge[i].w, pre);
			int v = DFS(edge[i].y, u, t);
			pre -= v;
			sum += v;
			edge[i].w -= v;
			edge[i ^ 1].w += v;
			if (pre == 0)
				break;
		}
	return sum;
}

int get_maxflow(int s, int t)
{
	int flow = 0;
	for (int i = 0; i < edgen; ++i)
		edge[i].w = edge[i].orig_w;
	while (BFS(t, s))
		flow += DFS(s, INF, t);
	return flow;
}

void BFS2(int s)
{
	static int que[MAXN];
	int qb = 0, qe = 1;
	memset(vis, 0, sizeof(vis));
	vis[s] = true;
	que[0] = s;
	while (qb < qe)
	{
		int x = que[qb++];
		for (int i = ehead[x]; i != -1; i = edge[i].next)
			if (edge[i].w && !vis[edge[i].y])
			{
				vis[edge[i].y] = true;
				que[qe++] = edge[i].y;
			}
	}
}

void init()
{
	for (int i = 1; i < n; ++i)
	{
		int flow = get_maxflow(i, fa[i]);
		ans += flow;
		faw[i] = flow;
		BFS2(i);
		for (int j = i + 1; j < n; ++j)
			if (vis[j] && fa[j] == fa[i])
				fa[j] = i;
	}
}

void findmin(int x, int fa_x, int &res)
{
	for (int i = ehead[x]; i != -1; i = edge[i].next)
		if (edge[i].y != fa_x && edge[i].w)
		{
			if (res == -1 || edge[i].w < edge[res].w)
				res = i;
			findmin(edge[i].y, x, res);
		}
}

void work_ans(int x)
{
	static int ansn;
	int id = -1;
	findmin(x, -1, id);
	if (id == -1)
	{
		ansp[ansn++] = x;
		return;
	}
	edge[id].w = edge[id ^ 1].w = 0;
	work_ans(edge[id].y);
	work_ans(edge[id ^ 1].y);
}

void solve()
{
	edgen = 0;
	memset(ehead, -1, sizeof(ehead));
	for (int i = 1; i < n; ++i)
	{
		addedge(i, fa[i], faw[i]);
		addedge(fa[i], i, faw[i]);
	}
	work_ans(1);
	printf("%d\n", ans);
	for (int i = 0; i < n; ++i)
		printf("%d ", ansp[i] + 1);
	printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9219.in", "r", stdin);
	freopen("9219.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}