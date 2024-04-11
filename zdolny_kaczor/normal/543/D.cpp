# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;
const int MN = 2e5 + 44;
const int root = 1;
vector <int> graph[MN];
long long up[MN], down[MN];
void mul(long long &a, long long b)
{
	a = (a * b) % MOD;
}
void dfs1(int x)
{
	down[x] = 1;
	for (auto v : graph[x])
	{
		dfs1(v);
		mul(down[x], down[v] + 1);
	}
}
void dfs2(int x)
{
	for (auto v : graph[x])
		up[v] = up[x] + 1;
	for (int i = 0; i < 2; ++i)
	{
		long long temp = 1;
		for (auto v : graph[x])
		{
			mul(up[v], temp);
			mul(temp, down[v] + 1);
		}
		reverse(graph[x].begin(), graph[x].end());
	}
	for (auto v : graph[x])
		dfs2(v);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		graph[a].push_back(i);
	}
	dfs1(root);
	up[root] = 0;
	dfs2(root);
	for (int i =1 ; i <= n; ++i)
		printf("%d ", (int) ((up[i] + 1) * down[i] % MOD + MOD) % MOD);
	printf("\n");
}