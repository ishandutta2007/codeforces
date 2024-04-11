# include <cstdio>
const int MN = 533;
int res[MN][MN];
void solve(int x, int y, int len, int sign)
{
	if (len == 1)
		res[x][y] = sign;
	else
	{
		solve(x, y, len / 2, sign);
		solve(x, y + len / 2, len / 2, sign);
		solve(x + len / 2, y, len / 2, sign);
		solve(x + len / 2, y + len / 2, len / 2, -sign);
	}
}
int main()
{
	int k;
	scanf("%d", &k);
	solve(0, 0, 1 << k, 1);
	for (int i = 0; i < (1 << k); ++i)
	{
		for (int l = 0; l < (1 << k); ++l)
			if (res[i][l] == 1)
				printf("+");
			else
				printf("*");
		printf("\n");
	}
	
}