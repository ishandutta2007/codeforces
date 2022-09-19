# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
const int MN = 1e3 + 44;
const int out = 0;
vector <int> graf[MN];
struct circle
{
	int x, y, r;
};
bool operator<(circle a, circle b)
{
	return a.r > b.r;
}
long long sq(int a)
{
	return a * (long long) a;
}
bool includes(circle a, circle b)
{
	return sq(a.x - b.x) + sq(a.y - b.y) <= sq(b.r - a.r) && a.r <= b.r;
}
bool in(circle a, pair <int, int> b)
{
// 	printf("is (%d, %d) in (%d, %d r=%d)\n", b.first, b.second, a.x, a.y, a.r);
	return sq(a.x - b.first) + sq(a.y - b.second) <= sq(a.r);
}
circle spl[MN];
pair <int, int> point[MN];
int nr[MN];
int dist[MN][MN];
void dfs(int x, int y, int start, int d)
{
// 	printf("dfs in %d\n", x);
	dist[start][x] = d;
	for (auto v : graf[x])
		if (v != y)
			dfs(v, x, start, d + 1);
}
int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &point[i].first, &point[i].second);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &spl[i].r, &spl[i].x, &spl[i].y);
	sort(spl + 1, spl + m + 1);
	for (int i = 1; i <= m; ++i)
	{
		int up = out;
		for (int k = 1; k < i; ++k)
			if (includes(spl[i], spl[k]))
				up = k;
// 		printf("match %d %d\n", i, up);
		graf[up].push_back(i);
		graf[i].push_back(up);
	}
	for (int i = 1; i <= n; ++i)
	{
		nr[i] = out;
		for (int k = 1; k <= m; ++k)
			if (in(spl[k], point[i]))
				nr[i] = k;
// 		printf("%d is in %d\n", i, nr[i]);
	}
	for (int i = 0; i <= m; ++i)
		dfs(i, -1, i, 0);
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", dist[nr[a]][nr[b]]);
	}
}