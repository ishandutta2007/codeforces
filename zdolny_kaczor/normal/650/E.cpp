# include <cstdio>
# include <vector>
using namespace std;
const int MN = 5e5 + 44;
const int root = 1;
const int none = -1;
vector <int> graphor[MN]; //graph determining order of operations on graphhl
vector <int> graphhl[MN]; //graph on which I create H-L decomposition and use F&U on each path
class fupath
{
	vector <int> l;
	vector <int> r;
	vector <int> nrs;
	int len;
public:
	void init(vector <int> nrs_)
	{
		nrs = nrs_;
		len = nrs.size();
		l.resize(len);
		r.resize(len);
		for (int i = 0; i < len; ++i)
			l[i] = r[i] = i;
	}
	void rem(int x) //gets position
	{
		if (l[x] == x)
			l[x] = x - 1;
		if (r[x] == x)
			r[x] = x + 1;
	}
	int next(int x)//returns position
	{
		while (x < len && r[x] != x)
			x = r[x];
		if (x >= len)
			return none;
		else
			return x;
	}
	int pre(int x)
	{
		while (x >= 0 && l[x] != x)
			x = l[x];
		if (x < 0)
			return none;
		else
			return x;
	}
	int get(int x)
	{
		return nrs[x];
	}
};
int in[MN], out[MN];
int up[MN];
int size[MN];
int timer = 0;
void predfs(int x) //is OK
{
	up[x] = none;
	in[x] = timer;
	timer++;
	size[x] = 1;
	for (auto v : graphhl[x])
	{
		predfs(v);
		size[x] += size[v];
		up[v] = x;
	}
	out[x] = timer;
	timer++;
}
bool isunder(int a, int b) //is a under b
{
	return in[a] >= in[b] && out[a] <= out[b];
}
struct hl
{
	int nr, top;
	fupath * path;
};
hl hldec[MN]; //describing edge from x to parent[x], hl-paths are going down
void hl_rec(int x) //is OK
{
// 	printf("call hl %d\n", x);
	int top = x;
	vector <int> path;
	if (x != root)
		path.push_back(x);
	while (! graphhl[x].empty())
	{
		int wh = none, val = 0;
		for (auto v : graphhl[x])
			if (size[v] > val)
			{
				wh = v;
				val = size[v];
			}
		for (auto v : graphhl[x])
			if (v != wh)
				hl_rec(v);
		path.push_back(wh);
		x = wh;
	}
	fupath * p = new fupath;
	p -> init(path);
// 	printf("path from %d:", top);
	for (int i = 0; i < path.size(); ++i)
	{
// 		printf("%d ", path[i]);
		hldec[path[i]].nr = i;
		hldec[path[i]].top = top;
		hldec[path[i]].path = p;
	}
// 	printf("\n");
}
void hl_cou()
{
	for (auto v : graphhl[root])
		hl_rec(v);
}
int jump(int a)
{
	if (a == root)
		return root;
	int na = hldec[a].top;
	if (na == root)
		return root;
	else
		return up[na];
}
void moveup(int &a, int b)
{
	while (true)
	{
		int na = jump(a);
		if (isunder(b, na))
			return;
		else
			a = na;
	}
}
int lca(int a, int b)
{
	if (isunder(a, b))
		return b;
	else if (isunder(b, a))
		return a;
	moveup(a, b);
	moveup(b, a);
	int na = jump(a);
	int nb = jump(b);
	if (isunder(na, nb))
		return na;
	else
		return nb;
}
int removeup(int a, int b) //works if path from a to b is going up
{
	while (isunder(a, b) && a != b)
	{
// 		printf("%d -> %d\n", a, b);
		int canpos = hldec[a].path -> pre(hldec[a].nr);
// 		printf("canpos = %d\n", canpos);
		if (canpos == none)
		{
			a = jump(a);
			continue;
		}
		int cannr = hldec[a].path -> get(canpos);
		if (isunder(cannr, b) && cannr != b)
		{
			hldec[a].path -> rem(canpos);
			return cannr;
		}
		else
			return none;
	}
	return none;
}
int removedown(int a, int b) //works if path from a to b is going down
{
	int ans = none;
	while (isunder(b, a) && a != b)
	{
// 		printf("in %d -> %d\n", a, b);
		int bup = hldec[b].top;
// 		printf("bup = %d\n", bup);
		if (isunder(bup, a) && bup != a)
		{
// 			printf("is good\n");
			int can = hldec[bup].path -> next(0);
// 			printf("can = %d\n", can);
			if (can != none)
			{
				int ver = hldec[bup].path -> get(can);
// 				printf("ver = %d\n", ver);
				if (!isunder(ver, b) || ver == b)
					ans = ver;
			}
			b = up[bup];
		}
		else
		{
// 			printf("is bad\n");
			int can = hldec[a].path -> next(hldec[a].nr + 1);
			if (can != none)
			{
				int ver = hldec[bup].path -> get(can);
				if (!isunder(ver, b) || ver == b)
					ans = ver;
			}
			break;
		}
	}
// 	printf("ans = %d\n", ans);
	if (ans == none)
	{
// 		printf("error no edge found\n");
		return none;
	}
	hldec[ans].path -> rem(hldec[ans].nr);
	return ans;
}
int remove(int a, int b) //returns nr of lower end of removed edge
{
	int up = lca(a, b);
	int res = removeup(a, up);
	if (res == none)
		return removedown(up, b);
	else
		return res;
}
void clear(vector <int> g[], int x, int y = none)
{
	for (int i = 0; i < g[x].size(); ++i)
		if (g[x][i] != y)
			clear(g, g[x][i], x);
		else
		{
			g[x][i] = g[x].back();
			g[x].pop_back();
			i--;
		}
}
void read(int n, vector <int> g[])
{
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	clear(g, root);
}
pair <int, int> can(pair <int, int> a)
{
	return make_pair(min(a.first, a.second), max(a.first, a.second));
}
vector <pair <pair <int, int>, pair <int, int> > > answer;
void call(int x, int y = none)
{
	for (auto v : graphor[x])
		call(v, x);
	if (y != none)
	{
		int tov = remove(x, y);
		int tov2 = up[tov];
		pair <int, int> from = can(make_pair(x, y));
		pair <int, int> to = can(make_pair(tov, tov2));
		if (from != to)
			answer.push_back(make_pair(from, to));
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	read(n, graphor);
	read(n, graphhl);
	predfs(root);
	hl_cou();
// 	for (int i = 1; i <= n; ++i)
// 		printf("%d.%d\n", i, hldec[i].top);
// 	while (true)
// 	{
// 		int a, b;
// 		scanf("%d%d", &a, &b);
// 		printf("%d\n", removedown(a, b));
// 	}
	call(root, -1);
	printf("%d\n", (int) answer.size());
	for (auto x : answer)
	{
		printf("%d %d %d %d\n", x.first.first, x.first.second, x.second.first, x.second.second);
	}
}