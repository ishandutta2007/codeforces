# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
vector <int> graph[MN];
bool out[MN];
bool fortress[MN];
int n, m, k;
int around[MN];
void showfortress()
{
	for (int i = 1; i <= n; ++i)
		if (fortress[i])
			printf("%d is a fortress\n", i);
}
void dfs(int x, long double bound)
{
// 	printf("dfs in %d around = %d deg = %d\n", x, around[x], (int) graph[x].size());
	if (out[x])
// 	{
// 		printf("already out\n");
		return;
// 	}
	if (around[x] <= graph[x].size() * (1 - bound) && !fortress[x])
// 	{
// 		printf("still good\n");
		return;
// 	}
// 	printf("Bye bye\n");
// 	if (fortress[x])
// 		printf("is a fortress\n");
	out[x] = true;
	for (auto v : graph[x])
		around[v]++;
	for (auto v : graph[x])
		dfs(v, bound);
}
bool check(long double bound) //leaves current state in out array
{
// 	showfortress();
// 	printf("check %lf\n", (double) bound);
	for (int i = 1; i <= n; ++i)
	{
		out[i] = false;
		around[i] = 0;
	}
	for (int i = 1; i <= n; ++i)
		if (fortress[i])
			dfs(i, bound);
	for (int i = 1; i <= n; ++i)
		if (!out[i])
// 		{
// 			printf("return true\n");
			return true;
// 		}
// 	printf("return false\n");
	return false;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i)
	{
		int a;
		scanf("%d", &a);
		fortress[a] = true;
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	long double low = 0, high = 1, ans = 0;
	while (high - low > 0.5 / n / n)
	{
// 		printf("%lf - %lf\n", (double) low, (double) high);
		long double med = (low + high) / 2;
		if (check(med))
		{
			ans = med;
			low = med;
		}
		else
			high = med;
	}
	check(ans);
// 	printf("ans = %.2lf\n", (double) ans);
	vector <int> wh;
	for (int i = 1; i <= n; i++)
		if (!out[i])
			wh.push_back(i);
	printf("%d\n", (int) wh.size());
	for (auto x : wh)
		printf("%d ", x);
	printf("\n");
}