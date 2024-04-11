#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, i, j, s, Ans, Left[105][10005], Right[105][10005];
char str[105][10005];

int main()
{
	scanf("%d %d\n", &n, &m);
	for (i = 1; i <= n; i++)
	{
		gets(str[i] + 1);
		j = strlen(str[i] + 1);
		while (j >= 1 && str[i][j] != '1')
			j--;
		if (j == 0)
		{
			printf("-1\n");
			return 0;
		}
		
		else
		{
			if (str[i][1] == '1')
				Left[i][1] = 0;
			else
				Left[i][1] = m - j + 1;
			for (j = 2; j <= m; j++)
				if (str[i][j] == '1')
					Left[i][j] = 0;
				else
					Left[i][j] = Left[i][j - 1] + 1;
			j = 1;
			while (j <= m && str[i][j] != '1')
				j++;
			if (str[i][m] == '1')
				Right[i][m] = 0;
			else
				Right[i][m] = j;
			for (j = m - 1; j >= 1; j--)
				if (str[i][j] == '1')
					Right[i][j] = 0;
				else
					Right[i][j] = Right[i][j + 1] + 1;
		}
	}
	
	Ans = 2147483647;
	for (j = 1; j <= m; j++)
	{
		s = 0;
		for (i = 1; i <= n; i++)
			s += min(Left[i][j], Right[i][j]);
		Ans = min(Ans, s);
	}
	
	printf("%d\n", Ans);
	return 0;
}