# include <cstdio>
const int MN = 1 << 17;
int tree[MN * 2];
int read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return 0;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return read(l, r, wh * 2, lb, (lb + rb) / 2) ^ read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
void edit(int pos, int val)
{
	pos += MN;
	tree[pos] = val;
	pos/= 2;
	while (pos)
	{
		tree[pos] = tree[pos * 2] ^ tree[pos * 2 + 1];
		pos /= 2;
	}
}
int spl(int n, int cou)
{
	if ((n - (cou - 1) * cou / 2) % cou)
		return MN - 1;
	else
		return read((n - (cou - 1) * cou / 2) / cou, (n - (cou - 1) * cou / 2) / cou + cou - 1);
}
int last[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		for (int amo = 2; amo * (amo - 1) / 2 < i; ++amo)
		{
			int x = spl(i, amo);
			last[x] = i;
		}
		int k;
		for (k = 0; last[k] == i; ++k)
			;
		edit(i, k);
	}
	for (int i = 2; i * (i - 1) / 2 < n; ++i)
	{
		int d = spl(n, i);
		if (d == 0)
		{
			printf("%d\n", i);
			return 0;
		}
	}
	printf("-1\n");
}