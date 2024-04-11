# include <cstdio>
# include <cstdlib>
const int MN = 1e5 + 44;
const int MS = 3e3 + 3;
int up[MS][MS], down[MS][MS], left[MS][MS], right[MS][MS], is[MS][MS], nr[MS][MS];
bool corner[MS][MS];
int ujump[MS][MS], rjump[MS][MS];
int ulen[MS][MS], rlen[MS][MS];
int get(int arr[MS][MS], int x, int y)
{
	if (x < 0 || y < 0)
		return 0;
	else
		return arr[x][y];
}
void sumup(int arr[MS][MS])
{
	for (int i = 0; i < MS; ++i)
		for (int k = 0; k < MS; ++k)
			arr[i][k] += get(arr, i - 1, k) + get(arr, i, k - 1) - get(arr, i - 1, k - 1);
}
int sum(int arr[MS][MS], int x1, int y1, int x2, int y2) //wcznie
{
	return get(arr, x1 - 1, y1 - 1) - get(arr, x1 - 1, y2) - get(arr, x2, y1 - 1) + get(arr, x2, y2);
}
bool used[MN];
void check(int x, int y, int len)
{
// 	printf("check %d %d %d\n", x, y, len);
	if (
		x + len < MS && y + len < MS
		&& sum(is, x, y, x + len - 1, y + len - 1) == len * len
		&& sum(down, x, y, x + len - 1, y) == len
		&& sum(left, x, y, x, y + len - 1) == len
		&& sum(right, x + len - 1, y, x + len - 1, y + len - 1) == len
		&& sum(up, x, y + len - 1, x + len - 1, y + len - 1) == len
	)
	{
		for (int i = 0; i < len; ++i)
			for (int k = 0; k < len; ++k)
				used[nr[x + i][y + k]] = true;
		int cou = 0;
		for (int i = 0; i < MN; ++i)
			if (used[i])
				cou++;
		printf("YES %d\n", cou);
		for (int i = 0; i < MN; ++i)
			if (used[i])
				printf("%d ", i);
		printf("\n");
		exit(0);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int v = 1; v <= n; ++v)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		for (int i = x1; i < x2; ++i)
			for (int k = y1; k < y2; ++k)
			{
				is[i][k] = 1;
				nr[i][k] = v;
			}
		for (int i = x1; i < x2; ++i)
			down[i][y1] = up[i][y2 - 1] = 1;
		for (int k = y1; k < y2; ++k)
			left[x1][k] = right[x2 - 1][k] = 1;
		corner[x1][y1] = true;
		ujump[x1][y1] = y2 - y1;
		rjump[x1][y1] = x2 - x1;
	}
// 	for (int i = 0; i < MS; ++i)
// 		for (int k = 0; k < MS; ++k)
// 			if (corner[i][k])
// 			{
// 				printf("corner:%d %d jumps = r%d u%d\n", i, k, rjump[i][k], ujump[i][k]);
// 			}
	sumup(up);
	sumup(down);
	sumup(right);
	sumup(left);
	sumup(is);
	for (int i = MS - 1; i >= 0; --i)
		for (int k = MS - 1; k >= 0; --k)
			if (corner[i][k])
			{
				ulen[i][k] = ulen[i][k + ujump[i][k]] + 1;
				rlen[i][k] = rlen[i + rjump[i][k]][k] + 1;
			}
	for (int i = 0; i < MS; ++i)
		for (int k = 0; k < MS; ++k)
			if (ulen[i][k] > rlen[i][k])
				for (int wh = i; corner[wh][k]; wh += rjump[wh][k])
					check(i, k, wh - i + rjump[wh][k]);
			else
				for (int wh = k; corner[i][wh]; wh += ujump[i][wh])
					check(i, k, wh - k + ujump[i][wh]);
	printf("NO\n");
}