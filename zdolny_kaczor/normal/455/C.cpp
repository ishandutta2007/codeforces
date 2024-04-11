# include <cstdio>
# include <vector>
using namespace std;
const int MN = 3e5 + 44;
vector <int> graph[MN];
int u[MN];
int val[MN];
int find(int a)
{
	if (u[a] == a)
		return a;
	else
		return u[a] = find(u[a]);
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	val[a] = max(val[a], max(val[b], (val[a] + 1) / 2 + (val[b] + 1) / 2 + 1));
	u[b] = a;
}
int size(int a)
{
	return val[find(a)];
}
pair <int, int> furthest(int x, int y)
{
	pair <int, int> ret = make_pair(0, x);
	for (auto v : graph[x])
		if (v != y)
			ret = max(ret, furthest(v, x));
	return make_pair(ret.first + (y != -1 ? 1 : 0), ret.second);
}
int diameter(int x)
{
	pair <int, int> a = furthest(x, -1);
	return furthest(a.second, -1).first;
}
int main()
{
	for (int i = 0; i < MN; ++i)
		u[i] = i;
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
		unite(a, b);
	}
	for (int i = 1; i <= n; ++i)
		if (find(i) == i)
		{
			val[i] = diameter(i);
// 			printf("dia %d = %d\n", i, val[i]);
		}
	while (q--)
	{
		int t;
		scanf("%d", &t);
		int x;
		if (t == 1)
		{
			scanf("%d", &x);
			printf("%d\n", size(x));
		}
		else
		{
			int a, b;
			scanf("%d%d", &a, &b);
			unite(a, b);
		}
	}
}