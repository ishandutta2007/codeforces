# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1 << 20;
pair <int, int> tree[MN * 2];
pair <int, int> make(pair <int, int> a, pair <int, int> b)
{
	return make_pair(max(a.first, b.first), min(a.second, b.second));
}
pair <int, int> neu = make_pair(-1e9, 1e9);
pair <int, int> read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return neu;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return make(read(l, r, wh * 2, lb, (lb + rb) / 2), read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
}
int val(pair <int, int> a)
{
	return min(a.first, a.second);
}
int res[MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tree[i + MN].first);
		tree[i + MN].first *= 100;
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", &tree[i + MN].second);
	for (int i = n; i < MN; ++i)
		tree[i + MN] = neu;
	for (int i = MN - 1; i; --i)
		tree[i] = make(tree[i * 2], tree[i * 2 + 1]);
	int bound = 0;
	for (int pos = 0; pos < n; ++pos)
	{
		if (bound < pos)
			bound = pos;
		pair <int, int> curr = read(pos, bound);
// 		printf("read %d %d from %d-%d\n", curr.first, curr.second, pos, bound);
		while (bound < n - 1 && curr.first < curr.second)
		{
			pair <int, int> next = make(curr, tree[bound + 1 + MN]);
			if (val(next) < val(curr))
				break;
			curr = next;
			bound ++;
		}
		res[pos] = val(curr);
// 		printf("res %d - %d (%d)\n", pos, bound, res[pos]);
	}
	sort(res, res + n);
		long double pra = (long double) k / n;
		long double exp = 0;
	for (int a = 0; a < n; ++a)
	{
		exp += pra * res[a];
// 		printf("i = %d pra = %lf\n", a, (double) pra);
		if (n == a - 1)
			break;
		pra *= (long double) (n - a - k) / (n - a - 1);
	}
	printf("%.10lf\n", (double) exp);
}