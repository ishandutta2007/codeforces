#include <algorithm>
#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int INF = 0x3f3f3f3f;

namespace flow
{

const int MAXN = 12005;
const int MAXM = 64005;

int n, s, t;
int edgey[MAXM];
int edgew[MAXM];
int enext[MAXM];
int ehead[MAXN];
int edgen;

int dis[MAXN];

void clear()
{
	edgen = 0;
	memset(ehead, -1, sizeof(ehead));
}

void add_one_edge(int x, int y, int w)
{
	edgey[edgen] = y;
	edgew[edgen] = w;
	enext[edgen] = ehead[x];
	ehead[x] = edgen++;
}

void addedge(int x, int y, int w)
{
	add_one_edge(x, y, w);
	add_one_edge(y, x, 0);
}

bool BFS()
{
	static int que[MAXN];
	int qb = 0, qe = 1;
	que[0] = t;
	memset(dis, INF, sizeof(dis));
	dis[t] = 0;

	while (qb < qe)
	{
		int x = que[qb++];
		for (int i = ehead[x]; i != -1; i = enext[i])
			if (dis[edgey[i]] == INF && edgew[i ^ 1])
			{
				dis[edgey[i]] = dis[x] + 1;
				que[qe++] = edgey[i];
			}
	}

	return dis[s] < INF;
}

int DFS(int x, int pre)
{
	if (x == t)
		return pre;
	int sum = 0;
	for (int i = ehead[x]; i != -1; i = enext[i])
		if (edgew[i] && dis[x] == dis[edgey[i]] + 1)
		{
			int u = std::min(pre, edgew[i]);
			int v = DFS(edgey[i], u);
			pre -= v;
			sum += v;
			edgew[i] -= v;
			edgew[i ^ 1] += v;
			if (!pre)
				break;
		}
	return sum;
}

int max_flow()
{
	int flow = 0;
	while (BFS())
		flow += DFS(s, INF);
	return flow;
}

}

int ans;

void init()
{
	const int MAXN = 10005;
	const int MAXM = 2005;
	const int MAXK = 15;
	int n, m, g;
	static int col[MAXN];
	static int v[MAXN];
	static int q[MAXM];
	static int w[MAXM];
	static int k[MAXM];
	static int req[MAXM][MAXK];

	scanf("%d%d%d", &n, &m, &g);
	for (int i = 0; i < n; ++i)
		scanf("%d", &col[i]);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &q[i], &w[i], &k[i]);
		for (int j = 0; j < k[i]; ++j)
		{
			scanf("%d", &req[i][j]);
			--req[i][j];
		}
		int fl;
		scanf("%d", &fl);
		if (fl)
		{
			ans -= g;
			w[i] += g;
		}
	}

	flow::clear();
	int flow_s = n + m;
	int flow_t = n + m + 1;
	for (int i = 0; i < n; ++i)
	{
		if (col[i] == 0)
			flow::addedge(i, flow_t, v[i]);
		else
			flow::addedge(flow_s, i, v[i]);
	}
	for (int i = 0; i < m; ++i)
	{
		ans += w[i];
		if (q[i] == 0)
		{
			flow::addedge(n + i, flow_t, w[i]);
			for (int j = 0; j < k[i]; ++j)
				flow::addedge(req[i][j], n + i, INF);
		}
		else
		{
			flow::addedge(flow_s, n + i, w[i]);
			for (int j = 0; j < k[i]; ++j)
				flow::addedge(n + i, req[i][j], INF);
		}
	}
	flow::n = n + m + 2;
	flow::s = flow_s;
	flow::t = flow_t;
}

void solve()
{
	ans -= flow::max_flow();
	printf("%d\n", ans);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9205.in", "r", stdin);
	freopen("9205.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}