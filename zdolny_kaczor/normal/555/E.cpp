# include <cstdio>
# include <cassert>
# include <cstdlib>
# include <vector>
using namespace std;
const int MN = 2e5 + 44;
vector <int> graph[MN];
vector <int> stack;
int nr[MN];
int timer = 1;
int ret[MN];
int cnr[MN];
int connected[MN];
const int NONE = -1;
vector <int> forest[MN];
int u[MN];
int ccou = 0;
int find(int x)
{
	if (u[x] == x)
		return x;
	else
		return u[x] = find(u[x]);
}
void unite(int a, int b)
{
	u[find(a)] = find(b);
}
int lca[MN];
const int VISITED = -1;
vector <pair <int, int> > queries[MN];
bool seen[MN];
pair <int, int> d[MN];
void lcacou(int x, int y)
{
// 	printf("lca cou in %d (%d)\n", x, y);
	seen[x] = true;
	for (auto q : queries[x])
	{
// 		printf("see %d %d\n", q.first, q.second);
		if (lca[q.second] == VISITED)
			lca[q.second] = find(q.first);
		else
			lca[q.second] = VISITED;
	}
	for (auto v : forest[x])
		if (v != y)
			lcacou(v, x);
	if (y != NONE)
		unite(x, y);
}
void dfs(int x, int y)
{
	connected[x] = ccou;
	stack.push_back(x);
	nr[x] = timer;
	ret[x] = nr[x];
	timer ++;
	bool Double = false;
	for (auto v : graph[x])
		if (v != y || Double)
		{
			if (nr[v] == 0)
			{
				dfs(v, x);
				ret[x] = min(ret[x], ret[v]);
			}
			else
				ret[x] = min(ret[x], nr[v]);
		}
		else
			Double = true;
	if (ret[x] == nr[x])
	{
		while (true)
		{
			int next = stack.back();
			stack.pop_back();
			cnr[next] = x;
			if (next == x)
				break;
		}
	}
}
bool checked[MN];
void err()
{
	printf("No\n");
	exit(0);
}
pair <int, int> operator + (pair <int, int> a, pair <int, int> b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}
pair <int, int> check(int x, int y)
{
	pair <int, int> ret = make_pair(0, 0);
	checked[x] = true;
	for (auto v : forest[x])
		if (v != y)
			ret = ret + check(v, x);
	ret = ret + d[x];
	if (ret.first && ret.second)
		err();
// 	assert(y != NONE || ret == make_pair(0, 0));
	return ret;
}
pair <int, int> paths[MN];
int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
		u[i] = i;
	for (int i = 1; i <= n; ++i)
		if (nr[i] == 0)
		{
			dfs(i, NONE);
			ccou++;
		}
// 	for (int i = 1; i <= n; ++i)
// 		printf("%d in %d\n", i, cnr[i]);
	for (int i = 1; i <= n; ++i)
		for (auto k : graph[i])
			if (cnr[i] != cnr[k])
// 			{
// 				printf("add %d (%d) <-> %d (%d)\n", cnr[i], i, cnr[k], k);
				forest[cnr[k]].push_back(cnr[i]);
// 			}
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (connected[a] != connected[b])
			err();
		a = cnr[a];
		b = cnr[b];
// 		printf("make query %d %d\n", a, b);
		if (a == b)
			lca[i] = a;
		else
		{
			queries[a].push_back(make_pair(b, i));
			queries[b].push_back(make_pair(a, i));
		}
		paths[i] = make_pair(a, b);
	}
	for (int i = 1; i <= n; ++i)
		if (!seen[i])
			lcacou(i, NONE);
	for (int i = 0; i < q; ++i)
	{
// 		printf("lca in %d\n", lca[i]);
		d[paths[i].first].first++;
		d[lca[i]].first--;
		d[paths[i].second].second++;
		d[lca[i]].second--;
	}
	for (int i = 1; i <= n; ++i)
		if (!checked[i])
			check(i, NONE);
	printf("Yes\n");
}