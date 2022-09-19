# include <cstdio>
# include <cstdlib>
const int MN = 111;
char mapa[MN][MN];
void err()
{
	printf("NO\n");
	exit(0);
}
void remove(int a, int b)
{
	if (mapa[a][b] != '#')
		err();
	mapa[a][b] = '.';
}
int main()
{
	int n;
	scanf("%d%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%s", mapa[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= n; ++k)
			if (mapa[i][k] == '#')
			{
				remove(i, k);
				remove(i + 1, k);
				remove(i + 1, k - 1);
				remove(i + 1, k + 1);
				remove(i + 2, k);
			}
	printf("YES\n");
}