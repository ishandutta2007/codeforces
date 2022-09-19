# include <cstdio>
# include <vector>
using namespace std;
const int MN = 4e5 + 44;
vector <pair <int, int> > graph[MN];
int color[MN];
void dfs(int x, int col)
{
	while (graph[x].size())
	{
		pair <int, int> e = graph[x].back();
		graph[x].pop_back();
		if (color[e.second] == 0)
		{
			color[e.second] = col;
			dfs(e.first, 3 - col);
			return;
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		y += MN / 2;
		graph[x].push_back(make_pair(y, i));
		graph[y].push_back(make_pair(x, i));
	}
	for (int i = 0; i < MN; ++i)
	{
		int k = 1;
		while (graph[i].size())
		{
			dfs(i, k);
			k = 3 - k;
		}
	}
	for (int i = 0; i < n; ++i)
		if (color[i] == 1)
			printf("r");
		else
			printf("b");
	printf("\n");
}