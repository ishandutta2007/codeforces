# include <cstdio>
# include <cstdlib>
int mask(int a, int b, int c)
{
	return (1<<a)|(1<<b)|(1<<c);
}
char board[4][4];
int diags[8]={mask(0, 1, 2), mask(3, 4, 5), mask(6, 7, 8), mask(0, 3, 6),
	mask(1, 4, 7), mask(2, 5, 8), mask(0, 4, 8), mask(2, 4, 6)};
int main()
{
	scanf("%s%s%s", board[0], board[1], board[2]);
	int x=0, o=0;
	int xmask=0, omask=0;
	for (int i=0; i<3; ++i)
		for (int k=0; k<3; ++k)
		{
			int id = 1<< (i*3+k);
			if (board[i][k]=='X')
			{
				x++;
				xmask+=id;
			}
			else if (board[i][k]=='0')
			{
				o++;
				omask+=id;
			}
		}
	bool xwon=false, owon=false;
	for (int i=0; i<8; ++i)
	{
		if ((xmask&diags[i])==diags[i])
			xwon=true;
		if ((omask&diags[i])==diags[i])
			owon=true;
	}
	if ((owon && xwon) || o>x || x>o+1 || (owon && x!=o) || (xwon && x!=o+1))
	{
		printf("illegal\n");
	}
	else if (owon)
		printf("the second player won\n");
	else if (xwon)
		printf("the first player won\n");
	else if (x+o==9)
		printf("draw\n");
	else if (x==o)
		printf("first\n");
	else
		printf("second\n");
}