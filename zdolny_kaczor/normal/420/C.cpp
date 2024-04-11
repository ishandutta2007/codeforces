# include <cstdio>
# include <map>
const int MN = 3e5 + 44;
using namespace std;
map <pair <int, int>, int> graph;
int deg[MN];
int cou[MN];
int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[make_pair(min(a, b), max(a, b))] ++;
		deg[a] ++;
		deg[b] ++;
	}
	for (int i = 1; i <= n; ++i)
		cou[deg[i]] ++;
	long long sum = 0;
	long long res = 0;
	for (int i = n; i >= 0; --i)
	{
		sum += cou[i];
		if (p - i >= 0)
		{
			res += sum * cou [p - i];
		}
	}
	for (int i = p + 1; i <= n; ++i)
		res += sum * cou[i];
	for (int i = 0; i < n; ++i)
		if (i * 2 >= p)
			res -= cou[i];
	res /= 2;
	for (auto x : graph)
	{
		int sum = deg[x.first.first] + deg[x.first.second];
		if (sum >= p && sum - x.second < p)
			res--;
	}
	printf("%I64d\n", res);
}