# include <cstdio>
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
struct ver
{
	int cou, min, div;
	ver(int a = 0)
	{
		min = div = a;
		cou = 1;
		if (a == 0)
		{
			min = 1e9 + 44;
			cou = 0;
		}
	}
};
ver mul(ver a, ver b)
{
	ver res;
	res.div = gcd(a.div, b.div);
	if (a.min < b.min)
	{
		res.min = a.min;
		res.cou = a.cou;
	}
	else if (a.min == b.min)
	{
		res.min = a.min;
		res.cou = a.cou + b.cou;
	}
	else
	{
		res.min = b.min;
		res.cou = b.cou;
	}
	return res;
}
const ver neu = ver();
const int MN = 1 << 17;
ver tree[MN * 2];
ver read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return neu;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return mul(read(l, r, wh * 2, lb, (lb + rb) / 2), read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d", &x);
		tree[i + MN] = ver(x);
	}
	for (int i = MN - 1; i; --i)
		tree[i] = mul(tree[i * 2], tree[i * 2 + 1]);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		ver x = read(l, r);
		if (x.div == x.min)
			printf("%d\n", r - l + 1 - x.cou);
		else
			printf("%d\n", r - l + 1);
	}
}