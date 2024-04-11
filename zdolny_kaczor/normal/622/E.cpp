# include <cstdio>
# include <vector>
# include <algorithm>
const int MN = 5e5 + 44;
using namespace std;
vector <int> graf[MN];
int dep[MN];
int dfs(int x, int y = -1, int d = 1)
{
	int ret = 0;
	int cou = 0;
	for (int v : graf[x])
		if (v != y)
		{
			ret = max(ret, dfs(v, x, d + 1));
			cou ++;
		}
	if (cou == 0)
	{
// 		printf("add (dfs) = %d\n", d);
		dep[d]++;
		return d;
	}
	else
		return ret;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int glres = 0;
	for (int v : graf[1])
	{
// 		printf("subtree %d\n", v);
		int res = 0;
		int d = dfs(v, 1);
// 		printf("ret d = %d\n", d);
		for (int i = 0; i <= d; ++i)
		{
			for (int x = 0; x < dep[i]; ++x)
			{
// 				printf("add %d\n", i);
				res = max(i, res + 1);
			}
			dep[i] = 0;
		}
		glres = max(res, glres);
	}
	printf("%d\n", glres);
}