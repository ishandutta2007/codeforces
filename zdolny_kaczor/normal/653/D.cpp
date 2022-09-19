# include <cstdio>
# include <algorithm>
# include <vector>
# include <cmath>
using namespace std;
const int MN = 52;
const int inf = 7e7 + 44;
vector <pair <int, int> > graph[MN];
int n, m, x;
int flow[MN][MN];
void make_graph(long double bound)
{
// 	printf("make %lf\n", (double) bound);
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= n; ++k)
			flow[i][k] = 0;
	for (int i = 1; i <= n; ++i)
		for (auto x : graph[i])
			flow[i][x.first] = floor(min(x.second / bound, 1e5l));
}
bool visited[MN];
void show()
{
	for (int i = 1; i <= n; ++i)
	{
		for (int k = 1; k <= n; ++k)
			printf("%5d ", flow[i][k]);
		printf("\n");
	}
	printf("\n\n");
}
int order[MN][MN];
int findpath(int x, int to, int max_capacity)//returns amount used
{
	if (visited[x] || max_capacity == 0)
		return 0;
	if (x == to)
		return max_capacity;
	visited[x] = true;
	int res = 0;
	for (int a = 1; a <= n; ++a)
	{
		int i = order[x][a];
		int cou = findpath(i, to, min(flow[x][i], max_capacity));
		flow[x][i] -= cou;
		flow[i][x] += cou;
		res += cou;
		max_capacity -= cou;
	}
// 	visited[x] = false;
	return res;
}
bool check(int from, int to, int bound)
{
	bool found = true;
	int res = 0;
	while (found)
	{
		for (int i = 1; i <= n; ++i)
			visited[i] = false;
		int add = findpath(from, to, bound);
		found = add > 0;
		bound -= add;
		if (bound == 0)
			return true;
// 		show();
	}
// 	printf("return %d\n", res);
	return false;
}
int main()
{
	scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i < n; ++i)
	{
		for (int k = 1; k <= n; ++k)
			order[i][k] = k;
		random_shuffle(order[i] + 1, order[i] + n + 1);
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
	}
	long double low = 0, high = 1e6 * x;
	while (high - low > 1e-7)
	{
		long double med = (high + low) / 2;
		make_graph(med / x);
		if (check(1, n, x))
			low = med;
		else
			high = med;
	}
	printf("%.10lf\n", (double) low);
}