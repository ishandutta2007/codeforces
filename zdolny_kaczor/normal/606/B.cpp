# include <cstdio>
# include <cstring>
const int MN = 510;
bool vis [MN][MN];
int x, y;
int m, n;
void move(char d)
{
	if (d=='D')
	{
		if (x<m)
			x++;
	}
	else if (d=='U')
	{
		if (x>1)
			x--;
	}
	else if (d=='R')
	{
		if (y<n)
			y++;
	}
	else
	{
		if (y>1)
			y--;
	}
}
const int ML = 100*1000+42;
char prog[ML];
int main()
{
	scanf("%d%d%d%d%s", &m, &n, &x, &y, prog);
	int cou = 1;
	int len = strlen(prog);
	printf("1 ");
	vis[x][y]=true;
	for (int i=0; i<len-1; ++i)
	{
// 		printf("(%d %d)\n", x, y);
		move(prog[i]);
		if (!vis[x][y])
		{
			printf("1 ");
			cou++;
		}
		else
			printf("0 ");
		vis[x][y]=true;
	}
// 	printf("m = %d n = %d cou = %d\n", m, n, cou);
	printf("%d\n", n*m-cou);
}