# include <cstdio>
const int A = 26;
const int MN = 1 << 17;
int tree[A][MN * 2];
int fall[A][MN * 2];
const int NO_PUSH = -1;
void push(int tree[], int fall[], int wh, int len)
{
	if (wh < MN && fall[wh] != NO_PUSH)
	{
		fall[wh * 2] = fall[wh * 2 + 1] = fall[wh];
		tree[wh * 2] = tree[wh * 2 + 1] = fall[wh] * (len / 2);
	}
	fall[wh] = NO_PUSH;
}
void show(int tree[], int fall[])
{
	for (int i = 1; i < MN * 2; ++i)
		printf("%d. fall = %d tree = %d\n", i, fall[i], tree[i]);
}
void init(int tree[], int fall[])
{
	for (int i = 0; i < MN * 2; ++i)
	{
		tree[i] = 0;
		fall[i] = NO_PUSH;
	}
}
void edit(int tree[], int fall[], int l, int r, int val, int wh = 1, int lb = 0, int rb = MN - 1)
{
// 	if (wh == 1)
// 		printf("edit %d - %d v = %d\n", l, r, val);
// 	printf("edit %d - %d in %d - %d (%d)\n", l, r, lb, rb, wh);
	push(tree, fall, wh, rb - lb + 1);
	if (l > rb || r < lb)
		return;
	if (l <= lb && r >= rb)
	{
		tree[wh] = val * (rb - lb + 1);
		fall[wh] = val;
	}
	else
	{
		edit(tree, fall, l, r, val, wh * 2, lb, (lb + rb) / 2);
		edit(tree, fall, l, r, val, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
		tree[wh] = tree[wh * 2] + tree[wh * 2 + 1];
	}
}
int read(int tree[], int fall[], int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
// 	if (wh == 1)
// 		printf("read %d - %d\n", l, r);
// 	printf("read %d - %d in %d - %d (%d)\n", l, r, lb, rb, wh);
	push(tree, fall, wh, rb - lb + 1);
	if (l > rb || r < lb)
		return 0;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return read(tree, fall, l, r, wh * 2, lb, (lb + rb) / 2) + read(tree, fall, l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
char input[MN];
void reset(int tree[], int fall[])
{
	int len = MN * 2;
	for (int i = 1; i < MN * 2; ++i)
	{
		if ((i & -i) == i)
			len /= 2;
		push(tree, fall, i, len);
	}
}
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < A; ++i)
		init(tree[i], fall[i]);
	scanf("%s", input + 1);
	for (int i = 1; i <= n; ++i)
		edit(tree[input[i] - 'a'], fall[input[i] - 'a'], i, i, 1);
	while (q--)
	{
		int i, j, k;
		scanf("%d%d%d", &i, &j, &k);
// 		printf("query %d - %d (%d)\n", i, j, k);
		int cou[A];
		for (int x = 0; x < A; ++x)
		{
// 			printf("read on letter %d\n", x);
			cou[x] = read(tree[x], fall[x], i, j);
			edit(tree[x], fall[x], i, j, 0);
		}
// 		for (int x = 0; x < A; ++x)
// 			printf("found %d letters %c\n", cou[x], 'a' + x);
		if (k == 1)
		{
			int pos = i;
			for (int x = 0; x < A; ++x)
				if (cou[x])
				{
// 					printf("write on letter %d\n", x);
					edit(tree[x], fall[x], pos, pos + cou[x] - 1, 1);
					pos += cou[x];
				}
		}
		else
		{
			int pos = j;
			for (int x = 0; x < A; ++x)
				if (cou[x])
				{
// 					printf("write on letter %d\n", x);
					edit(tree[x], fall[x], pos - cou[x] + 1, pos, 1);
					pos -= cou[x];
				}
		}
	}
	for (int i = 1; i <= n; ++i)
		for (int x = 0; x < A; ++x)
			if (read(tree[x], fall[x], i, i))
				putchar('a' + x);
	printf("\n");
}