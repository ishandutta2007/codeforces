# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
vector <pair <int, int> > graph[MN];
int u[MN];
int dep[MN];
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
vector <pair <int, int> > lca_queries[MN];
const int VISITED = -1;
int status[MN];
int enr[MN];
void lca_cou(int x, int y, int d)
{
	dep[x] = d;
	for (auto q : lca_queries[x])
		if (status[q.second] == VISITED)
			status[q.second] = find(q.first);
		else
			status[q.second] = VISITED;
	for (auto v : graph[x])
		if (v.first != y)
		{
			enr[v.first] = v.second;
			lca_cou(v.first, x, d + 1);
			unite(v.first, x);
		}
}
vector <int> up_paths[MN];
int ans[MN];
int sum_up[MN];
void ans_cou(int x, int y, int d)
{
	for (auto jumps : up_paths[x])
	{
		sum_up[d] ++;
		sum_up[jumps]--;
	}
	for (auto v : graph[x])
		if (v.first != y)
		{
			ans_cou(v.first, x, d + 1);
			sum_up[d] += sum_up[d + 1];
			sum_up[d + 1] = 0;
		}
	if (x != 1)
		ans[enr[x]] = sum_up[d];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		u[i] = i;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(make_pair(b, i));
		graph[b].push_back(make_pair(a, i));
	}
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		lca_queries[a].push_back(make_pair(b, i));
		lca_queries[b].push_back(make_pair(a, i));
	}
	lca_cou(1, -1, 0);
	for (int i = 1; i <= n; ++i)
		for (auto q : lca_queries[i])
			up_paths[i].push_back(dep[status[q.second]]);
// 	for (int i = 1; i <= n; ++i)
// 	{
// 		printf("%d:", i);
// 		for (auto v : up_paths[i])
// 			printf("%d ", v);
// 		printf("\n");
// 	}
	ans_cou(1, -1, 0);
	for (int i = 0; i < n - 1; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}