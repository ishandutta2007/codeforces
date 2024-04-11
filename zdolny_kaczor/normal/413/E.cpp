# include <cstdio>
# include <set>
using namespace std;
const int MN = 1 << 18;
const char vac = '.', occ = 'X';
const int inf = 1 << 27;
struct data
{
	int dist[2][2];
	bool neu;
	data()
	{
		neu = true;
	}
	data(char up, char down)
	{
		neu = false;
		dist[0][0] = (up == vac) ? 0 : inf;
		dist[1][1] = (down == vac) ? 0 : inf;
		dist[1][0] = dist[0][1] = (up == vac && down == vac) ? 1 : inf;
	}
};
data operator * (data a, data b)
{
	if (a.neu)
		return b;
	else if (b.neu)
		return a;
	data ret;
	ret.neu = false;
	for (int i = 0; i < 2; ++i)
		for (int k = 0; k < 2; ++k)
			ret.dist[i][k] = min(1 + min(a.dist[i][0] + b.dist[0][k], a.dist[i][1] + b.dist[1][k]), inf);
	return ret;
}
const data neu = data();
data tree[MN * 2];
data read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return neu;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return read(l, r, wh * 2, lb, (lb + rb) / 2) * read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
char maze[2][MN];
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s%s", maze[0], maze[1]);
	for (int i = 0; i < n; ++i)
		tree[i + MN] = data(maze[0][i], maze[1][i]);
	for (int i = MN - 1; i >= 0; --i)
		tree[i] = tree[i * 2] * tree[i * 2 + 1];
	for (int i = 0; i < q; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		if (a % n > b % n)
			swap(a, b);
		data from = read(a % n, b % n);
		int ans = from.dist[a / n][b / n];
		if (ans < inf)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
}