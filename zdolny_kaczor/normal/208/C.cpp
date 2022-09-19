# include <cstdio>
# include <vector>
# include <queue>
const int MN = 107;
long long cou1[MN], cou2[MN];
int dist1[MN], dist2[MN];
std::vector <int> graph[MN];
void bfs(int source, int n, long long cou[], int dist[])
{
	for (int i = 1; i <= n; ++i)
		cou[i] = 0, dist[i] = n + 1;
	std::queue <int> queue;
	queue.push(source);
	cou[source] = 1;
	dist[source] = 0;
	while (!queue.empty())
	{
		int curr = queue.front();
		queue.pop();
		for (auto v : graph[curr])
			if (dist[v] >= dist[curr] + 1)
			{
				if (dist[v] == n + 1)
					queue.push(v);
				dist[v] = dist[curr] + 1;
				cou[v] += cou[curr];
			}
	}
}
long long usage(int a, int b)
{
	if (dist1[a] + dist2[b] + 1 == dist2[1])
		return cou1[a] * cou2[b];
	else if (dist2[a] + dist1[b] + 1 == dist2[1])
		return cou2[a] * cou1[b];
	else
		return 0;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(1, n, cou1, dist1);
	bfs(n, n, cou2, dist2);
	long long max = 0;
	for (int i = 1; i <= n; ++i)
	{
		long long res = 0;
		for (auto v : graph[i])
			res += usage(i, v);
		max = std::max(max, res);
	}
	printf("%.8f\n", (double) max / cou1[n]);
}