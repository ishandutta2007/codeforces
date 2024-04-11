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

int n, k, i, s, x, Ans;

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s = 0;
		while (x > 0)
		{
			if (x % 10 == 4 || x % 10 == 7)
				s++;
			x /= 10;
		}
		
		if (s <= k)
			Ans++;
	}
	
	printf("%d\n", Ans);	
	return 0;
}