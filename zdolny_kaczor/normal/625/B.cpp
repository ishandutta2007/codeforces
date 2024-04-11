# include <cstdio>
# include <cstring>
const int MN = 1e5 + 66;
char string [MN];
char both[MN];
int p[MN]; //najduszy waciwy p-s podsowa od [0...i] (dugo)
int main()
{
	scanf("%s%s", string, both);
	int n = strlen(string);
	int m = strlen(both);
	int l = m + n + 1;
	both[m] = '!';
	for (int i = 0; i <= n; ++i)
		both[i + m + 1] = string[i];
	p[0] = 0;
	for (int i = 1; i < l; ++i)
	{
		int x = p[i - 1];
		while (x > 0 && both[x] != both[i])
			x = p[x - 1];
		if (both[x] == both[i])
			x++;
		p[i] = x;
// 		printf("%d %d\n", i, p[i]);
	}
// 	printf("%s\n", both);
// 	for (int i = 0; i < l; ++i)
// 	{
// 		printf("%d.%d\n", i, p[i]);
// 	}
	int res = 0, pos = 0;
	for (int i = m + 1; i < l; ++i)
		if (p[i] >= m)
		{
			if (i >= pos)
			{
				pos = i + m;
				res ++;
			}
		}
	printf("%d\n", res);
}