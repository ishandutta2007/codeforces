# include <cstdio>
# include <vector>
# include <cstdlib>
# include <algorithm>
using namespace std;
const int MN = 1e5 + 44;
vector <int> graph[MN];
vector <int> graph2[MN];
void err()
{
	printf("-1\n");
	exit(0);
}
int inter(int a, int b)
{
	int res = 0;
	for (auto x : graph[a])
		for (auto y : graph[b])
			if (x == y)
				res ++;
	return res;
}
int u[MN];
void init(int n)
{
	for (int i = 1; i <= n; ++i)
		u[i] = i;
}
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
bool visited[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n * 2; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
		if (graph[i].size() != 4)
			err();
	if (n < 8)
	{
		int per[n];
		for (int i = 0; i < n; ++i)
			per[i] = i + 1;
		do
		{
			bool all = true;
			for (int i = 0; i < n; ++i)
				for (int k = 1; k <= 2; ++k)
				{
					int dest = (i + k) % n;
					bool found = false;
					for (auto x : graph[per[i]])
						if (x == per[dest])
							found = true;
					if (!found)
						all = false;
				}
			if (all)
			{
				for (int i = 0; i < n; ++i)
					printf("%d ", per[i]);
				return 0;
			}
		}
		while (next_permutation(per, per + n));
		printf("-1\n");
		return 0;
	}
	init(n);
	for (int i = 1; i <= n; ++i)
	{
		for (auto v : graph[i])
			if (inter(i, v) == 2)
			{
				graph2[i].push_back(v);
				unite(i, v);
			}
	}
	for (int i = 1; i <= n; ++i)
		if (graph2[i].size() != 2)
			err();
	for (int i = 2; i <= n; ++i)
		if (find(i) != find(1))
			err();
	int in = 1;
	int cou = 1;
	visited[in] = true;
	printf("%d ", in);
	while (cou < n)
	{
		for (auto x : graph2[in])
			if (!visited[x])
			{
				in = x;
				break;
			}
		cou++;
		visited[in] = true;
		printf("%d ", in);
	}
	printf("\n");
}