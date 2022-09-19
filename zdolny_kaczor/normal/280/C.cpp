# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
vector <int> G[MN];
long double res = 0;
void dfs(int x, int y, int d)
{
	res += 1 / (long double) d;
	for (auto v : G[x])
		if (y != v)
			dfs(v, x, d + 1);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1, -1, 1);
	printf("%lf\n", (double) res);
}