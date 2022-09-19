# include <cstdio>
# include <algorithm>
# include <vector>
const int MN = 2e5 + 44;
using namespace std;
vector <int> graph[MN];
pair <int, int> input[MN];
int up[MN];
int val[MN];
void dfs1(int x, int y = -1)
{
	up[x] = y;
	for (auto v : graph[x])
		if (v != y)
			dfs1(v, x);
}
vector <int> res;
int opt = 1 << 24;
void dfs2(int x, int y, int sum)
{
	sum += val[x];
// 	printf("in %d with %d\n", x, sum);
	if (sum < opt)
	{
		res.clear();
		res.push_back(x);
		opt = sum;
	}
	else if (sum == opt)
		res.push_back(x);
	for (auto v : graph[x])
		if (v != y)
			dfs2(v, x, sum);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		input[i] = make_pair(a, b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs1(1);
	int add = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (up[input[i].first] == input[i].second)
		{
			val[input[i].first]--;
			add++;
		}
		else
			val[input[i].second]++;
	}
	dfs2(1, -1, 0);
	printf("%d\n", opt + add);
	sort(res.begin(), res.end());
	for (auto x : res)
		printf("%d ", x);
}