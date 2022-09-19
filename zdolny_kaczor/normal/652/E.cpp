# include <cstdio>
# include <vector>
using namespace std;
const int MN = 3e5 + 44;
vector <pair <int, bool> > graph[MN];
int ret[MN];
bool visited[MN];
int up[MN];
int nr[MN];
int timer;
vector <pair <int, bool> > tree[MN];
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
// 	printf("unite %d %d\n", a, b);
	u[find(a)] = find(b);
}
void dfs(int x, int y = -1)
{
	nr[x] = timer;
	ret[x] = timer;
	visited[x] = true;
	timer ++;
	up[x] = y;
	for (auto v : graph[x])
		if (v.first != y)
		{
// 			printf("%d -> %d\n", x, v.first);
			if (visited[v.first])
				ret[x] = min(ret[x], nr[v.first]);
			else
			{
				dfs(v.first, x);
				ret[x] = min(ret[x], ret[v.first]);
			}
		}
	if (y != -1 && ret[x] != nr[x])
		unite(x, y);
}
bool hasartifact[MN];
enum {not_found, no_artifact, artifact_found};
char dfs2(int x, int dest, int from = -1)
{
	if (x == dest)
		return hasartifact[dest] ? artifact_found : no_artifact;
	else
		for (auto v : tree[x])
			if (v.first != from)
			{
				char subtree_ret = dfs2(v.first, dest, x);
				if (subtree_ret == artifact_found)
					return artifact_found;
				else if (subtree_ret == no_artifact)
					return (v.second || hasartifact[x]) ? artifact_found : no_artifact;
			}
	return not_found;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		u[i] = i;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back(make_pair(b, (bool) c));
		graph[b].push_back(make_pair(a, (bool) c));
	}
	int a, b;
	scanf("%d%d", &a, &b);
	dfs(1);
// 	for (int i = 1; i <= n; ++i)
// 		printf("component_nr[%d] = %d\n", i, ret[i]);
	for (int i = 1; i <= n; ++i)
		for (auto v : graph[i])
			if (v.first < i)
			{
				if (find(i) == find(v.first))
				{
					if (v.second)
						hasartifact[find(i)] = true;
				}
				else
				{
					tree[find(i)].push_back(make_pair(find(v.first), v.second));
					tree[find(v.first)].push_back(make_pair(find(i), v.second));
				}
			}
	char status = dfs2(find(a), find(b));
	if (status == no_artifact)
		printf("NO\n");
	else
		printf("YES\n");
}