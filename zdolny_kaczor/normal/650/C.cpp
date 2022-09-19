# include <cstdio>
# include <vector>
# include <algorithm>
# include <queue>
using namespace std;
const int MN = 1e6 + 44;
int m, n;
int arr[MN];
inline int make_coo(int x, int y)
{
	return x * m + y;
}
int u[MN];
void fuinit()
{
	for (int i = 0; i < MN; ++i)
		u[i] = i;
}
int find(int a)
{
	if (u[a] == a)
		return a;
	else
		return u[a] = find(u[a]);
}
void unite(int a, int b)
{
	u[find(a)] = find(b);
}
vector <pair <int, int> > edges;
void scan(pair <int, int> tab[], int len)
//tab stores <val, coo>
{
	sort(tab, tab + len);
// 	printf("scan has recieved:");
// 	for (int i = 0; i < len; ++i)
// 		printf("<%d, %d> ", tab[i].first, tab[i].second);
// 	printf("\n");
	for (int i = 0; i < len - 1; ++i)
		if (tab[i].first == tab[i + 1].first)
			unite(tab[i].second, tab[i + 1].second);
		else
			edges.push_back(make_pair(tab[i].second, tab[i + 1].second));
}
pair <int, int> get(int i, int k)
{
	return make_pair(arr[make_coo(i, k)], make_coo(i, k));
}
vector <int> graf[MN];
int ans[MN];
int deg[MN];
int bound[MN];
queue <int> sources;
pair <int, int> data[MN];
int main()
{
	fuinit();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
			scanf("%d", arr + make_coo(i, k));
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < m; ++k)
			data[k] = get(i, k);
		scan(data, m);
	}
	for (int k = 0; k < m; ++k)
	{
		for (int i = 0; i < n; ++i)
			data[i] = get(i, k);
		scan(data, n);
	}
	for (auto v : edges)
	{
		graf[find(v.first)].push_back(find(v.second));
		deg[find(v.second)]++;
	}
// 	for (int i = 0; i < MN; ++i)
// 		for (auto v : graf[i])
// 			printf("%d -> %d\n", i, v);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
		{
			int nr = make_coo(i, k);
			if (deg[nr] == 0 && find(nr) == nr)
				sources.push(nr);
		}
	while (!sources.empty())
	{
		int last = sources.front();
		sources.pop();
		ans[last] = 1 + bound[last];
		for (auto v : graf[last])
		{
			bound[v] = max(bound[v], ans[last]);
			deg[v]--;
			if (deg[v] == 0)
				sources.push(v);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < m; ++k)
			printf("%d ", ans[find(make_coo(i, k))]);
		printf("\n");
	}
}