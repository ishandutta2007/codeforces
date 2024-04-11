# include <cstdio>
const int MN = 21;
char input[MN];
int factors[MN];
void mul(int x, int sign)
{
	for (int p = 2; p < MN; ++p)
		while (x % p == 0)
		{
			x /= p;
			factors[p] += sign;
		}
}
int main()
{
	int n;
	scanf("%*d%s", input);
	for (int i = 0; input[i]; ++i)
	{
		int dig = input[i] - '0';
		for (int p = 2; p <= dig; ++p)
			mul(p, +1);
	}
	for (int p = MN - 1; p >= 0; --p)
		while (factors[p])
		{
			printf("%d", p);
			for (int i = 2; i <= p; ++i)
				mul(i, -1);
		}
	printf("\n");
}