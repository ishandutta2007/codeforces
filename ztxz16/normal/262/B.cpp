#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

int n, k, i, x, Min, Ans;

int main()
{
	scanf("%d %d", &n, &k);
	Min = 1616161616;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		if (x < 0)
		{
			if (k > 0)
			{
				k--, Ans -= x;
				if (0 - x < Min)
					Min = 0 - x;
			}
			
			else
				Ans += x;
		}
		
		else
		{
			Ans += x;
			if (x < Min)
				Min = x;
		}
	}
	
	if ((k & 1) == 1)
		Ans -= (Min << 1);
	printf("%d\n", Ans);
	return 0;
}