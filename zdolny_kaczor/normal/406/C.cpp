# include <cstdio>
# include <vector>
# include <queue>
using namespace std;
const int MN = 1e5 + 44;
int dep[MN];
pair <int, int> edges[MN];
bool used[MN];
int rdeg[MN], bdeg[MN];
char color[MN];
const char red = 1, blue = 2;
priority_queue <pair <int, int> > with, without;
void rdec(int x)
{
	rdeg[x] --;
}
void bdec(int x)
{
	bdeg[x] --;
}
void show(int a, int b)
{
// 	printf("show %d %d\n", a, b);
	used[a] = used[b] = true;
	if (color[a] == red)
	{
		rdec(edges[a].first);
		rdec(edges[a].second);
	}
	else
	{
		bdec(edges[a].first);
		bdec(edges[a].second);
	}
	if (color[b] == red)
	{
		rdec(edges[b].first);
		rdec(edges[b].second);
	}
	else
	{
		bdec(edges[b].first);
		bdec(edges[b].second);
	}
	if (edges[a].first == edges[b].first || edges[a].first == edges[b].second)
		swap(edges[a].first, edges[a].second);
	printf("%d %d %d\n", edges[a].first, edges[a].second, edges[a].second ^ edges[b].first ^ edges[b].second);
}
vector <pair <int, int> > graph[MN];
bool visited[MN];
pair <int, int> up[MN];
vector <pair <int, int> > rgr[MN], bgr[MN];
void colorb(int x)
{
	bgr[edges[x].first].push_back(make_pair(edges[x].second, x));
	bgr[edges[x].second].push_back(make_pair(edges[x].first, x));
	bdeg[edges[x].first]++;
	bdeg[edges[x].second]++;
	color[x] = blue;
}
pair <int, int> take(vector <pair <int, int> > & from)
{
	while (used[from.back().second])
		from.pop_back();
	pair <int, int> ret = from.back();
	from.pop_back();
	return ret;
}
void dfs(int v, int d = 0)
{
	dep[v] = d;
	visited[v] = true;
	for (auto x : graph[v])
	{
		if (color[x.second] != 0)
			continue;
		if (visited[x.first])
		{
// 			printf("blue %d - %d (%d)\n", v, x.first, x.second);
			colorb(x.second);
		}
		else
		{
// 			printf("red %d - %d\n", v, x.first);
			up [x.first] = make_pair(v, x.second);
			rgr[v].push_back(x);
			rdeg[v] ++;
			color[x.second] = red;
			dfs(x.first, d + 1);
		}
	}
}
void check(int i)
{
// 	printf("check %d\n", i);
	if (rdeg[i] == 0 && i != 1)
	{
// 		printf("is\n");
		if (bdeg[i])
			with.push(make_pair(dep[i], i));
		else
			without.push(make_pair(dep[i], i));
	}
}
int main()
{
	int m, n;
	scanf("%d%d", &n, &m);
	if (m % 2)
	{
		printf("No solution\n");
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(make_pair(b, i));
		graph[b].push_back(make_pair(a, i));
		edges[i] = make_pair(a, b);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i)
	{
// 		printf("in %d\n", i);
		while (bdeg[i] > 1)
		{
// 			printf("deg[%d] = %d\n", i, bdeg[i]);
			pair <int, int> a = take(bgr[i]), b = take(bgr[i]);
			show(a.second, b.second);
		}
	}
// 	printf("removed blue\n");
	for (int i = 2; i <= n; ++i)
		check(i);
	while (!with.empty() || !without.empty())
	{
		if (with.empty())
		{
			int nr = without.top().second;
// 			printf("take %d (without)\n", nr);
			without.pop();
			if (used[up[nr].second])
				continue;
			if (bdeg[up[nr].first])
			{
				show(up[nr].second, take(bgr[up[nr].first]).second);
				check(up[nr].first);
			}
			else if (rdeg[up[nr].first] > 1)
			{
// 				printf("rdeg[%d] = %d", up[nr].first, rdeg[up[nr].first] );
				pair <int, int> a = take(rgr[up[nr].first]);
				if (a.first == nr)
					a = take(rgr[up[nr].first]);
				show(up[nr].second, a.second);
				check(up[nr].first);
			}
			else
			{
// 				printf("go up up\n");
				show(up[nr].second, up[up[nr].first].second);
				check(up[up[nr].first].first);
			}
		}
		else
		{
			int nr = with.top().second;
// 			printf("take %d (with)\n", nr);
			with.pop();
			show(up[nr].second, take(bgr[nr]).second);
			check(up[nr].first);
		}
// 		getchar();
	}
}