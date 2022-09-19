# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1 << 19;
long long tree[MN * 2];
long long fall[MN * 2];
int left[MN], right[MN];
int timer = 0;
vector <int> graph[MN];
void dfs(int x, int y = -1)
{
	left[x] = timer;
	right[x] = timer;
	timer ++;
	for (auto v : graph[x])
		if (v != y)
		{
			dfs(v, x);
			right[x] = right[v];
		}
}
void push(int wh)
{
	if (fall[wh])
	{
		if (wh < MN)
			fall[wh * 2] = fall[wh * 2 + 1] = fall[wh];
		tree[wh] = fall[wh];
		fall[wh] = 0;
	}
}
long long read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
// 	printf("read (%d), %d - %d\n", wh, lb, rb);
	push(wh);
	if (l > rb || r < lb)
		return 0;
	else if (lb >= l && rb <= r)
		return tree[wh];
	else
		return read(l, r, wh * 2, lb, (lb + rb) / 2) | read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
void write(int l, int r, long long val, int wh = 1, int lb = 0, int rb = MN - 1)
{
// 	printf("write (%d), %d - %d\n", wh, lb, rb);
	push(wh);
// 	printf("pushed\n");
	if (l > rb || r < lb)
		return;
	else if (lb >= l && rb <= r)
	{
		fall[wh] = val;
		push(wh);
	}
	else
	{
// 		printf("go down\n");
		write (l, r, val, wh * 2, lb, (lb + rb) / 2);
		write (l, r, val, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
		tree[wh] = tree[wh * 2] | tree[wh * 2 + 1];
	}
}
int color[MN];
int main()
{
	if (MN != 1 << 19)
		printf("ERROR with MN !!!!!!!!!!!!!!!!!!!!!!\n");
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
		scanf("%d", color + i);
	for (int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs(1);
// 	for (int i = 1; i <= n; ++i)
// 		printf("%d: %d - %d\n", i, left[i], right[i]);
	for (int i = 1; i <= n; ++i)
		tree[left[i] + MN] = 1LL << color[i];
	for (int i = MN - 1; i; --i)
		tree[i] = tree[i * 2] | tree[i * 2 + 1];
	while (q--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int v, c;
			scanf("%d%d", &v, &c);
// 			printf("write %d - %d (%d), %dc\n", left[v], right[v], v, c);
			write(left[v], right[v], 1LL << c);
		}
		else
		{
			int v;
			scanf("%d", &v);
// 			printf("read %d - %d (%d)\n", left[v], right[v], v);
			long long a = read(left[v], right[v]);
// 			printf("read %llx\n", a);
			int res = 0;
			for (int i = 0; i < 64; ++i)
				if (a & (1LL << i))
					res++;
// 			printf("\t\tANSWER:\t\t");
			printf("%d\n", res);
		}
// 		for (int i = 1; i < MN * 2; ++i)
// 			printf("%d. key = %llx push = %llx\n", i, tree[i], fall[i]);
	}
}