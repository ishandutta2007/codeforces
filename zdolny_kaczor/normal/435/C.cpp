# include <cstdio>
# define MY 1010
# define MX 2010
char res[MX][MY];
int x=1002, y=0;
int maxx(int a, int b)
{
	return a>b?a:b;
}
int last(int x)
{
	int qwe=-1;
	for (int i=0; i<MY; ++i)
		if (res[x][i]!=' ')
			qwe=i;
// 	printf("last(%d)=%d\n", x, qwe);
	return qwe;
}
int main()
{
	for (int i=0; i<MX; ++i)
		for (int k=0; k<MY; ++k)
			res[i][k]=' ';
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int a;
		scanf("%d", &a);
		if (i%2)
			while (a--)
			{
				res[x][y]='\\';
// 				printf("res[%d][%d]=\'\\\'\n", x, y);
				x++;
				y++;
			}
		else
			while (a--)
			{
				x--;
				res[x][y]='/';
// 				printf("res[%d][%d]=\'/\'\n", x, y);
				y++;
			}
	}
	int min;
	int max;
	for (min=0; last(min)==-1; ++min)
		;
	for (max=MX-1; last(max)==-1; --max)
		;
	int len=0;
	for (int i=min; i<=max; ++i)
		len=maxx(len, last(i));
// 	printf("%d-%d\n", min, max);
	for (int i=min; i<=max; ++i)
	{
		for (int k=0; k<=len; ++k)
			putchar(res[i][k]);
		putchar(10);
	}
}