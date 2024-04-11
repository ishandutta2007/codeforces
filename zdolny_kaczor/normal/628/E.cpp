# include <cstdio>
# include <cassert>
# include <vector>
using namespace std;
const int MN = 1 << 12;
int tree[MN * 2];
vector <int> kol[MN];
void reset()
{
	for (int i = 0; i < MN; ++i)
		assert(kol[i].empty());
// 	printf("reset\n");
	for (int i = 0; i < MN * 2; ++i)
		assert(tree[i] == 0);
}
void add(int pos, int val)
{
// 	printf("add %d in %d\n", val, pos);
	pos += MN;
	while (pos)
	{
		tree[pos] += val;
		pos /= 2;
	}
}
int sumr(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
// 	if (wh == 1)
// // 		printf("read %d - %d\n", l, r);
	if (l > rb || r < lb)
		return 0;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return sumr(l, r, wh * 2, lb, (lb + rb) / 2) + sumr(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
char tab[MN][MN];
int rlen[MN][MN], llen[MN][MN], diag[MN][MN], rdiag[MN][MN];
int main()
{
	int m, n;
	scanf("%d%d", &n, &m);
// 	printf("MN = %d\n", MN);
	for (int i = 1; i <= n; ++i)
		scanf("%s", tab[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= m; ++k)
			if (tab[i][k] == 'z')
				llen[i][k] = llen[i][k - 1] + 1;
			else
				llen[i][k] = 0;
	for (int i = n; i; --i)
		for (int k = m; k; --k)
			if (tab[i][k] == 'z')
				rlen[i][k] = rlen[i][k + 1] + 1;
			else
				rlen[i][k] = 0;
	for (int i = n; i; --i)
		for (int k = m; k; --k)
			if (tab[i][k] == 'z')
				diag[i][k] = diag[i + 1][k - 1] + 1;
			else
				diag[i][k] = 0;
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= m; ++k)
			if (tab[i][k] == 'z')
				rdiag[i][k] = rdiag[i - 1][k + 1] + 1;
			else
				rdiag[i][k] = 0;
// 	for (int i = 1; i <= n; ++i)
// 	{
// 		for (int k = 1; k <= m; ++k)
// 			printf("r%d, l%d, d%d, D%d;;\t", rlen[i][k], llen[i][k], diag[i][k], rdiag[i][k]);
// 		printf("\n");
// 	}
	long long res = 0;
	for (int nr = 2; nr <= m + n; ++nr)
	{
// 		printf("\n\niter over %d\n", nr);
// 			reset();
		for (int i = max (1, nr - m); i <= n && nr - i > 0; ++i)
		{
// 			printf("in %d %d\n", i, nr - i);
			if (tab[i][nr - i] == 'z')
			{
// 				printf("is \'z\'\n");
				add(i, +1);
// 				printf("added\n");
				res += sumr(i - min(rdiag[i][nr - i], rlen[i][nr - i]) + 1, i);
				kol[i + min(llen[i][nr - i], diag[i][nr - i]) - 1].push_back(i);
				for (auto x : kol[i])
					add(x, -1);
				kol[i].clear();
			}
		}
// 		printf("res = %I64d\n", res);
	}
	printf("%I64d\n", res);
}