# include <cstdio>
# include <cstring>
# include <cstdlib>
const int MN = 1e5 + 44;
char n[MN];
char res[MN];
void check(char tab[], int len, bool start)
{
// 	printf("len = %d\n", len);
	bool isdone = false, isneeded = start;
	for (int i = 0; i * 2 < len - 1; ++i)
	{
// 		printf("proceed %d %d with %d %d\n", tab[len - i - 1], tab[i], isdone, isneeded);
		int dig = tab[len - i - 1] - (isdone ? 1 : 0);
// 		printf("dig = %d\n", dig);
		int aim = tab[i] + (isneeded ? 10 : 0);
		if (aim == dig)
		{
			isneeded = false;
		}
		else if (aim - 1 == dig)
		{
			isneeded = true;
		}
		else if (aim - 1 == dig + 10)
		{
			dig += 10;
			isneeded = true;
		}
		else if (aim == dig + 10)
		{
			dig += 10;
			isneeded = false;
		}
		else
			return;
// 		printf("dig = %d\n", dig);
		if (dig > 18 || dig < 0)
			return;
		isdone = (dig + (isdone ? 1 : 0) > 9);
		res[i] = (dig + 1) / 2;
		res[len - i - 1] = dig / 2;
	}
	if (len % 2 == 0)
	{
		if (isdone != isneeded)
			return;
	}
	else
	{
		int dig = tab[len / 2] + (isneeded ? 10 : 0) - (isdone ? 1 : 0);
		if (dig < 0 || dig > 18 || dig % 2 != 0)
			return;
		res[len / 2] = dig / 2;
	}
	if (res [0] == 0)
		return;
	for (int i = 0; i < len; ++i)
		printf("%d", res[i]);
	printf("\n");
	exit(0);
}
int main()
{
	scanf("%s", n);
	int len = strlen(n);
	for (int i = 0; i < len; ++i)
		n[i] -= '0';
	check(n, len, false);
	if (n[0] == 1 && len >= 2)
		check(n + 1, len - 1, true);
	printf("0\n");
}