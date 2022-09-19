# include <cstdio>
# include <queue>
using namespace std;
const int MN = 3e3 + 44;
const int none = -1e7;
vector <int> graph[MN];
int dist[MN][MN];
pair <int, int> from[MN][3], to[MN][3];
void add(pair <int, int> arr[3], pair <int, int> x)
{
	for (int i = 0; i < 3; ++i)
		if (x > arr[i])
			swap(arr[i], x);
}
void bfs(int n, int start, int res[])
{
	for (int i = 1; i <= n; ++i)
		res[i] = none;
	queue <int> kol;
	kol.push(start);
	res[start] = 0;
	while (kol.size())
	{
		int curr = kol.front();
		kol.pop();
		for (auto x : graph[curr])
			if (res[x] == none)
			{
				kol.push(x);
				res[x] = res[curr] + 1;
			}
	}
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
	}
	for (int i = 1; i <= n; ++i)
		bfs(n, i, dist[i]);
// 	for (int i = 1; i <= n; ++i)
// 	{
// // 		for (int k = 1; k <= n; ++k)
// 			printf("%d ", dist[i][k]);
// 		printf("\n");
// 	}
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= n; ++k)
		{
			add(from[i], make_pair(dist[i][k], k));
			add(to[k], make_pair(dist[i][k], i));
		}
	int max = 0;
	int path[4];
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= n; ++k)
			for (pair <int, int> ll : to[i])
				for (pair <int, int> rr : from[k])
					if (ll.second && rr.second)
					{
						int l = ll.second;
						int r = rr.second;
	// 					printf("try %d %d %d %d\t", l, i, k, r);
						if (l != i && l != k && l != r && r != i && r != k && i != k)
						{
							int val = dist[l][i] + dist[i][k] + dist[k][r];
							if (val > max)
							{
								max = val;
								path[0] = l;
								path[1] = i;
								path[2] = k;
								path[3] = r;
							}
						}
					}
	for (int i : path)
		printf("%d ", i);
	printf("\n");
}