# include <cstdio>
# include <cstdlib>
const int MN = 4;
int x[MN], y[MN];
void res(int n)
{
	printf("%d\n", n);
	exit(0);
}
bool between(int a, int b, int c)
{
	return (a > b && b > c) || (a < b && b < c);
}
void two(int a, int b, int c, int x[], int y[])
{
	if (x[a] == x[c] && !between(y[a], y[b], y[c]))
		res(2);
}
int main()
{
	for (int i = 0; i < 3; ++i)
		scanf("%d%d", x + i, y + i);
	if (x[0] == x[1] && x[1] == x[2])
		res(1);
	if (y[0] == y[1] && y[1] == y[2])
		res(1);
	two(0, 1, 2, x, y);
	two(1, 2, 0, x, y);
	two(2, 0, 1, x, y);
	two(0, 1, 2, y, x);
	two(1, 2, 0, y, x);
	two(2, 0, 1, y, x);
	res(3);
}