# include <cstdio>
# include <set>
typedef long double ld;
const int MN = 54;
ld dp[MN][MN][MN]; //[pocztek sufixu, liczba osb na sufixie, wynik
int a[MN];
long long pas[MN][MN];
ld pows[MN][MN];
void init()
{
	for (int i = 0; i < MN; ++i)
	{
		pas[i][i] = pas[i][0] = 1;
		for (int k = 1; k < i; ++k)
			pas[i][k] = pas[i - 1][k] + pas[i - 1][k - 1];
	}
	for (int i = 0; i < MN; ++i)
	{
		pows[i][0] = 1;
		for (int k = 1; k < MN; ++k)
			pows[i][k] = pows[i][k - 1] * i;
	}
}
ld pra(int all, int sel, int pos)
{
	ld ret = pas[all][sel] / pows[pos][all] * pows[pos - 1][all - sel];
// 	printf("pra(%d, %d, %d) = %Lf\n", all, sel, pos, ret);
	return ret;
}
inline int div(int a, int b)
{
// 	printf ("%d / %d\n", a, b);
	return (a + b - 1) / b;
}
int main()
{
	init();
	int len, amo;
	scanf("%d%d", &amo, &len);
	for (int i = 0; i < len; ++i)
		scanf("%d", a + i);
	dp[len][0][0] = 1;
	for (int pos = len - 1; pos >= 0; --pos)
		for (int curramo = 0; curramo <= amo; ++curramo)
			for (int take = 0; take <= curramo; ++take)
				for (int res = 0; res <= amo; ++res)
				{
					dp[pos][curramo][std::max(div(take, a[pos]), res)] += dp[pos + 1][curramo - take][res] * pra(curramo, take, len - pos);
				}
// 	for (int i = 0; i < len; ++i)
// 		for (int k = 0; k <= amo; ++k)
// 			for (int l = 0; l <= amo; ++l)
// 				printf("dp[%d][%d][%d] = %Lf\n", i, k, l, dp[i][k][l]);
	ld res = 0;
	for (int i = 0; i <= amo; ++i)
		res += i * dp[0][amo][i];
	printf("%.10lf\n", (double)res);
}