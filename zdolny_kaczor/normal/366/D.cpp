# include <cstdio>
# include <vector>
# include <queue>
using namespace std;
const int MN = 1e3 + 44;
const int inf = 7e7 + 44;
struct edge
{
	int dest, l, r;
	edge(int a, int b, int c)
	{
		dest = a;
		l = b;
		r = c;
	}
};
vector <edge> graph[MN];
int max_bound[MN];
priority_queue <pair <int, int> > kol;
int dijkstra(int n, int lower_bound)
{
// 	printf("dijkstra %d\n", lower_bound);
	for (int i = 1; i <= n; ++i)
		max_bound[i] = -inf;
	kol.push(make_pair(inf, 1));
	while (!kol.empty())
	{
		pair <int, int> current = kol.top();
// 		printf("enter dist = %d nr = %d\n", current.first, current.second);
		kol.pop();
		if (max_bound[current.second] >= current.first)
		{
// 			printf("already done\n");
			continue;
		}
		max_bound[current.second] = current.first;
		for (auto v : graph[current.second])
			if (v.l <= lower_bound)
			{
// 				printf("insert dist = %d nr = %d\n", min(v.r, current.first), v.dest);
				kol.push(make_pair(min(v.r, current.first), v.dest));
			}
	}
// 	printf("found %d\n", max_bound[n]);
	return max_bound[n] - lower_bound + 1;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b, l, r;
		scanf("%d%d%d%d", &a, &b, &l, &r);
		graph[a].push_back(edge(b, l, r));
		graph[b].push_back(edge(a, l, r));
	}
	int res = 0;
	for (int i = 1; i <= n; ++i)
		for (auto v : graph[i])
			if (v.dest > i)
				res = max(res, dijkstra(n, v.l));
	if (res < 1)
		printf("Nice work, Dima!\n");
	else
		printf("%d\n", res);
}