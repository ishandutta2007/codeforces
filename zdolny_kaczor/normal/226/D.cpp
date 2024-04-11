# include <cstdio>
const int MN = 101;
int tab[MN][MN];
int n, m;
int rsum[MN], csum[MN];
bool r[MN], c[MN];
void flip(int x, int y)
{
	tab[x][y] *= -1;
	rsum[x] += 2 * tab[x][y];
	csum[y] += 2 * tab[x][y];
}
bool rcast(int x)
{
	if (rsum[x] >= 0)
		return false;
// 	printf("rcast %d\n", x);
	r[x] = !r[x];
	for (int i = 0; i < m; ++i)
		flip(x, i);
	return true;
}
bool ccast(int x)
{
	if (csum[x] >= 0)
		return false;
// 	printf("ccast %d\n", x);
	c[x] = !c[x];
	for (int i = 0; i < n; ++i)
		flip(i, x);
	return true;
}
void show(bool a[], int len)
{
	int cou = 0;
	for (int i = 0; i < len; ++i)
		if (a[i])
			cou ++;
	printf("%d", cou);
	for (int i = 0; i < len; ++i)
		if (a[i])
			printf(" %d", i + 1);
	printf("\n");
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int k = 0; k < m; ++k)
		{
			scanf("%d", &tab[i][k]);
			rsum[i] += tab[i][k];
			csum[k] += tab[i][k];
		}
	bool any = true;
	while (any)
	{
		any = false;
		for (int i = 0; i < n; ++i)
			any = rcast(i) || any;
		for (int k = 0; k < m; ++k)
			any = ccast(k) || any;
	}
	show(r, n);
	show(c, m);
}