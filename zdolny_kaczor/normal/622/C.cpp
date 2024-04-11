# include <cstdio>
# include <set>
using namespace std;
typedef pair <pair <int, int>, pair <int, int> > T;
T make(T a, T b)
{
	return make_pair(min(a.first, b.first), max(a.second, b.second));
}
const int inf = 1 << 24;
const int MN = 1 << 20;
T tree[MN * 2];
T neu = make_pair(make_pair(inf, inf), make_pair(-inf, -inf));
T init(int x, int pos)
{
	pair <int, int> a = make_pair(x, pos);
	return make_pair(a, a);
}
T read(int l, int r, int wh, int lb, int rb)
{
// 	printf("read %d - %d in %d - %d (%d)\n", l, r, lb, rb, wh);
	if (l > rb || r < lb)
	{
// 		printf("neu\n");
		return neu;
	}
	else if (l <= lb && r >= rb)
	{
// 		printf("tree\n");
		return tree[wh];
	}
	else
	{
// 		printf("go down\n");
		return make(read(l, r, wh * 2, lb, (lb + rb) / 2), read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
	}
}
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i)
	{
		int a;
		scanf("%d", &a);
		tree[i + MN] = init(a, i);
	}
	for (int i = MN - 1; i; --i)
		tree[i] = make(tree[i * 2], tree[i * 2 + 1]);
	while (q--)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		T out = read (l, r, 1, 0, MN - 1);
// 		printf("%d %d, %d %d\n", out.first.first, out.first.second, out.second.first, out.second.second);
		if (out.first.first != x)
			printf("%d\n", out.first.second);
		else if (out.second.first != x)
			printf("%d\n", out.second.second);
		else
			printf("-1\n");
	}
}