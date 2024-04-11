# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
const int LOG = 18;
const int MN = 1 << LOG;
int u[MN];
int find(int a)
{
	if (u[a] == a)
		return a;
	else
		return u[a] = find(u[a]);
}
void unite(int a, int b)
{
	u[find(a)] = find(b);
}
int up_nr[MN][LOG];
int up_val[MN][LOG];
vector <pair <int, int> > tree[MN];
pair <int, pair <int, int> > edges[MN];
pair <int, pair <int, int> > queries[MN];
int in[MN], out[MN];
int timer;
void dfs(int x, int y)
{
	in[x] = timer;
	timer++;
	for (auto v : tree[x])
		if (v.second != y)
		{
// 			printf("dfs %d -> %d\n", x, v.second);
			up_nr[v.second][0] = x;
			up_val[v.second][0] = v.first;
			for (int i = 1; i < LOG; ++i)
			{
				up_nr[v.second][i] = up_nr[up_nr[v.second][i - 1]][i - 1];
				up_val[v.second][i] = max(up_val[v.second][i - 1], up_val[up_nr[v.second][i - 1]][i - 1]);
			}
			dfs(v.second, x);
		}
	out[x] = timer;
	timer++;
}
bool is_under(int a, int b)
{
	return in[a] >= in[b] && out[a] <= out[b];
}
int half_path_max(int a, int b)
{
// 	printf("half_path_max %d %d\n", a, b);
	if (is_under(b, a))
		return 0;
	int res = 0;
	for (int i = LOG - 1; i >= 0; --i)
		if (!is_under(b, up_nr[a][i]))
		{
			res = max(res, up_val[a][i]);
// 			printf("include %d\n", up_val[a][i]);
			a = up_nr[a][i];
// 			printf("jump to %d\n", a);
		}
	res = max(res, up_val[a][0]);
	return res;
}
int path_max(int a, int b)
{
	return max(half_path_max(a, b), half_path_max(b, a));
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		u[i] = i;
	for (int i = 0; i < m; ++i)
	{
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		queries[i] = edges[i] = make_pair(v, make_pair(x, y));
	}
	long long mst = 0;
	sort(edges, edges + m);
	for (int i = 0; i < m; ++i)
		if (find(edges[i].second.first) != find(edges[i].second.second))
		{
// 			printf("add %d <-> %d (%d)\n", edges[i].second.first, edges[i].second.second, edges[i].first);
			mst += edges[i].first;
			unite(edges[i].second.first, edges[i].second.second);
			tree[edges[i].second.first].push_back(make_pair(edges[i].first, edges[i].second.second));
			tree[edges[i].second.second].push_back(make_pair(edges[i].first, edges[i].second.first));
		}
	in[0] = -1;
	out[0] = MN * 2;
	dfs(1, -1);
// 	for (int i = 1; i <= n; ++i)
// 		for (int k = 0; up_nr[i][k]; ++k)
// 			printf("%d ^ 2 ^ %d --> %d\n", i, k, up_nr[i][k]);
	for (int i = 0; i < m; ++i)
		printf("%I64d\n", mst - path_max(queries[i].second.first, queries[i].second.second) + queries[i].first);
}