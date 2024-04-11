# include <cstdio>
# include <map>
# include <set>
# include <algorithm>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
const int inf = 1e9 + 44;
const int NONE = -1;
typedef pair <int, int> point;
map <pair <int, int>, int> weight;
	//weight[(a, b)] is the value added to result when moving from a to b
vector <int> graph[MN];
point points[MN];
point center;
const point zero = make_pair(0, 0);
map <pair <int, int>, int> nrinvector;
	//(x, graph[x][i]) = i, used to check if the loop is going clockwise
void shift(vector <int> & x, int value)
{
	int pos = -1;
	for (int i = 0; i < x.size(); ++i)
		if (x[i] == value)
		{
			pos = i;
			break;
		}
	
	vector <int> newvector;
	for (int i = (pos + 1) % x.size(); i != pos; i = (i + 1) % x.size())
		newvector.push_back(x[i]);
	x = newvector;
}
void set_pivot(point x)
{
	center = x;
}
point operator-(point a, point b)
{
	return make_pair(a.first - b.first, a.second - b.second);
}
long long operator * (point a, point b)
{
	return (long long) a.first * b.second - (long long) a.second * b.first;
}
bool cmp(int a, int b)
{
	point va = points[a] - center, vb = points[b] - center;
	if (va > zero xor vb > zero)
	{
		return va > zero;
	}
	else
	{
		return va * vb < 0;
	}
}
char state[MN];
const char unseen = 0, inprogress = 1, done = 2;
typedef bool color;
set <pair <int, int> > red, blue;
void dfs(int x, int y = NONE)
{
	state[x] = inprogress;
	if (y != NONE)
		shift(graph[x], y);
	for (auto v : graph[x])
	{
		if (state[v] == inprogress)
			blue.insert(make_pair(x, v));
		else if (state[v] == unseen)
		{
			red.insert(make_pair(x, v));
			weight[make_pair(x, v)] = 1;
			dfs(v, x);
		}
		//else - blue edge going down
	}
	state[x] = done;
}
int sumupto[MN];
	/*
	sumupto[d] number of vertices strictly on the right of the path from root
	to current vertex whose LCA with current vertex has depth not higher than d
	*/
int dep[MN];
int dfscou(int x, int d) //returns the number of all vertices in x's subtree
{
	int res = 1;
	dep[x] = d;
	if (d)
		sumupto[d] = sumupto[d - 1];
	else
		sumupto[d] = 0;
	for (int i = graph[x].size() - 1; i >= 0; --i)
	{
		int v = graph[x][i];
		if (blue.find(make_pair(x, v)) != blue.end())
		{
			int val = sumupto[dep[x]] - sumupto[dep[v]] + dep[x] - dep[v] + 1;
			weight[make_pair(x, v)] = - val + 2;
			weight[make_pair(v, x)] = val - 1;
		}
		else if (red.find(make_pair(x, v)) != red.end())
		{
			int under =  dfscou(v, d + 1);
			sumupto[d] += under;
			res += under;
		}
	}
	return res;
}
int cycle[MN];
int calcres(int len)
{
	int res = 1;
	for (int i = 0; i < len; ++i)
		res += weight[make_pair(cycle[i], cycle[(i + 1) % len])];
	return res;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &points[i].first, &points[i].second);
	for (int i = 1; i <= n; ++i)
	{
		set_pivot(points[i]);
		sort(graph[i].begin(), graph[i].end(), cmp);
	}
	point maximal = make_pair(inf, inf);
	int start;
	for (int i = 1; i <= n; ++i)
		if (maximal > points[i])
		{
			start = i;
			maximal = points[i];
		}
	dfs(start);
	dfscou(start, 0);
	for (int i = 1; i <= n; ++i)
		for (int k = 0; k < graph[i].size(); ++k)
			nrinvector[make_pair(i, graph[i][k])] = k;
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int len;
		scanf("%d", &len);
		for (int i = 0; i < len; ++i)
			scanf("%d", cycle + i);
		int tophei = MN;
		int topi;
		for (int i = 0; i < len; ++i)
			if (dep[cycle[i]] < tophei)
			{
				tophei = dep[cycle[i]];
				topi = i;
			}
		int dir1 = nrinvector[make_pair(cycle[topi], cycle[(topi + 1) % len])];
		int dir2 = nrinvector[make_pair(cycle[topi], cycle[(topi + len - 1) % len])];
		if (dir1 < dir2)
			reverse(cycle, cycle + len);
		printf("%d\n", calcres(len));
	}
}