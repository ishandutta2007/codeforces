# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
const int LOG = 17;
int jump[MN][LOG];
vector <int> down[MN];
vector <int> roots;
int timer;
int in[MN], out[MN];
int dep[MN];
void inoutcou(int x, int d)
{
	dep[x] = d;
	in[x] = timer;
	timer++;
	for (auto v : down[x])
		inoutcou(v, d + 1);
	out[x] = timer;
	timer++;
}
# define nr first
# define vertex second
vector <pair <int, int> > queries[MN];
int ans[MN];
vector <int> ondep[MN];
int moveup(int x, int c)
{
	for (int i = 0; (1 << i) <= c; ++i)
		if ((1 << i) & c)
			x = jump[x][i];
	return x;
}
const int SIZE = 1 << 18;
int tree[SIZE * 2];
int read(int l, int r, int wh = 1, int lb = 0, int rb = SIZE - 1)
{
	if (l > rb || r < lb)
		return 0;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return read(l, r, wh * 2, lb, (lb + rb) / 2) + read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
void edit(int pos, int val)
{
	pos += SIZE;
	tree[pos] = val;
	pos /= 2;
	while (pos > 0)
	{
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		pos /= 2;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &jump[i][0]);
		if (jump[i][0] == 0)
			roots.push_back(i);
	}
	for (int i = 1; i < LOG; ++i)
		for (int x = 1; x <= n; ++x)
			jump[x][i] = jump[jump[x][i - 1]][i - 1];
	for (int i = 1; i <= n; ++i)
		down[jump[i][0]].push_back(i);
	for (auto r : roots)
		inoutcou(r, 0);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i)
	{
		int p, v;
		scanf("%d%d", &v, &p);
		int top = moveup(v, p);
		if (top != 0)
			queries[dep[v]].push_back(make_pair(i, top));
	}
	for (int i = 1; i <= n; ++i)
		ondep[dep[i]].push_back(i);
	for (int i = 0; i < n; ++i)
	{
		for (auto x : ondep[i])
			edit(in[x], +1);
		for (auto q : queries[i])
			ans[q.nr] = read(in[q.vertex], out[q.vertex]) - 1;
		for (auto x : ondep[i])
			edit(in[x], 0);
	}
	for (int i = 0; i < q; ++i)
		printf("%d ", ans[i]);
}