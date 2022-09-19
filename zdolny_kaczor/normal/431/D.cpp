# include <cstdio>
const long long MAX_RES = 1e18;
const int MN = 64;
long long binomial[MN][MN];
void init()
{
	for (int i = 0; i < MN; ++i)
		binomial[i][i] = binomial[i][0] = 1;
	for (int i = 1; i < MN; ++i)
		for (int k = 1; k < i; ++k)
			binomial[i][k] = binomial[i - 1][k] + binomial[i - 1][k - 1];
}
long long bin(int n, int m)
{
	if (n < 0 || m < 0)
		return 0;
	else
		return binomial[n][m];
}
long long cou(long long bound, int bits)
{
// 	printf("cou %I64d %d\n", bound, bits);
	int left = bits;
	long long res = 0;
	for (int i = 63; i >= 0; --i)
		if ((1LL << i) & bound)
		{
// 			printf("add %d | %d\n", i - 1, left);
			res += bin(i, left);
			left --;
		}
// 	printf("return %I64d\n", res);
// 	getchar();
	return res;
}
int main()
{
	init();
	long long m;
	int k;
	scanf("%I64d%d", &m, &k);
	long long low = 1, high = MAX_RES;
	while (true)
	{
// 		printf("%I64d - %I64d\n", low, high);
		long long med = (low + high) / 2;
		long long val = cou(med, k - 1);
		if (val == m)
		{
			printf("%I64d\n", med);
			return 0;
		}
		else if (val < m)
			low = med + 1;
		else
			high = med - 1;
	}
}