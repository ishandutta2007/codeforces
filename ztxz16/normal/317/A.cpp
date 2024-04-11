#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long x, y, m, s, Ans;

int main()
{
	scanf("%I64d %I64d %I64d", &x, &y, &m);
	if (x > y)
		s = x;
	else
		s = y;
	if (s >= m)
		printf("0\n");
	else if (x <= 0 && y <= 0)
		printf("-1\n");
	else
	{
		if (x <= 0)
		{
			Ans += (0 - x) / y;
			x = 0 - ((0 - x) % y);
		}
		
		if (y <= 0)
		{
			Ans += (0 - y) / x;
			y = 0 - ((0 - y) % x);
		}
		
		while (x < m && y < m)
		{
			s = x + y;
			if (x < y)
				x = s;
			else
				y = s;
			Ans++;
		}
		
		printf("%I64d\n", Ans);
	}
	
	
	return 0;
}