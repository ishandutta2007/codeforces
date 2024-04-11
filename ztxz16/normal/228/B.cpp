#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n1, m1, n2, m2, i, x, y;
int Ans, Ans_x, Ans_y;
char a[105][105], b[105][105];

void Work(int x, int y);

int main()
{
	scanf("%d %d\n", &n1, &m1);
	for (i = 1; i <= n1; i++)
		gets(a[i] + 1);
	scanf("%d %d\n", &n2, &m2);
	for (i = 1; i <= n2; i++)
		gets(b[i] + 1);
	Ans = 0;
	Ans_x = Ans_y = -50;
	for (x = -50; x <= 50; x++)
		for (y = -50; y <= 50; y++)
			Work(x, y);
	printf("%d %d\n", Ans_x, Ans_y);
	return 0;
}

void Work(int x, int y)
{
	if (x == 1 && y == 1)
		x = 1;
	int i, j, s = 0;
	for (i = 1; i <= n1; i++)
		for (j = 1; j <= m1; j++)
		{
			if (i + x < 1 || i + x > n2)
				continue;
			if (j + y < 1 || j + y > m2)
				continue;
			s += ((a[i][j] - 48) * (b[i + x][j + y] - 48));
		}
	
	if (s > Ans)
		Ans = s, Ans_x = x, Ans_y = y;
	return;
}