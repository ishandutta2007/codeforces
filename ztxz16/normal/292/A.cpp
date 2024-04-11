#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, t[1005], c[1005], s, Ans, Max, Now;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d %d", &t[i], &c[i]);
	Now = 1;
	for (i = 1; i <= 2000000; i++)
	{
		if (s > 0)
		{
			s--;
			if (s == 0)
				Ans = i;
			if (t[Now] == i)
				s += c[Now], Now++;
		}
		
		else
		{
			if (t[Now] == i)
				s += c[Now], Now++;
		}
		
		if (s > Max)
			Max = s;
	}
	
	if (s > 0)
		Ans = 2000000 + s;
	printf("%d %d\n", Ans, Max);
	return 0;
}