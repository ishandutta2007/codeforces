# include <cstdio>
# include <set>
using namespace std;
const int inf = 1e9 + 44;
const int MN = 1 << 17;
pair <int, int> tree[MN * 2];
pair <int, int> compose(pair <int, int> a, pair <int, int> b)
{
	return make_pair(max(a.first, b.first), min(a.second, b.second));
}
pair <int, int> neu = make_pair(-inf, inf);
pair <int, int> read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return neu;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return compose(read(l, r, wh * 2, lb, (lb + rb) / 2), read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
}
int dp[MN * 2];
void edit(int pos, int val)
{
	pos += MN;
	dp[pos] = val;
	pos /= 2;
	while (pos)
	{
		dp[pos] = min(dp[pos * 2], dp[pos * 2 + 1]);
		pos /= 2;
	}
}
int readdp(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return inf;
	else if (l <= lb && r >= rb)
		return dp[wh];
	else
		return min(readdp(l, r, wh * 2, lb, (lb + rb) / 2), readdp(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
}
int last[MN];
int main()
{
	int n, s, l;
	scanf("%d%d%d", &n, &s, &l);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		tree[i + MN] = make_pair(x, x);
	}
	for (int i = n; i < MN; ++i)
		tree[i] = neu;
	for (int i = MN - 1; i; --i)
		tree[i] = compose(tree[i * 2], tree[i * 2 + 1]);
	int bound = 0;
	for (int pos = 0; pos < n; ++pos)
	{
		if (bound < pos)
			bound = pos;
		pair <int, int> temp = read(pos, bound);
		while (bound < n - 1)
		{
			pair <int, int> next = compose(temp, tree[bound + 1 + MN]);
			if (next.first - next.second > s)
				break;
			temp = next;
			bound ++;
		}
		last[pos] = bound + 1;
	}
// 	for (int i = 0; i < n; ++i)
// 		printf("%d:%d\n", i, last[i]);
	dp[n] = 0;
	for (int i = n - 1; i >= 0; --i)
		if (last[i] < i + l)
			edit(i, inf);
		else
			edit(i, 1 + readdp(i + l, last[i]));
	if (dp[MN] >= inf)
		printf("-1\n");
	else
		printf("%d\n", dp[MN]);
}