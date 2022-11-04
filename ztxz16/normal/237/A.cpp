#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b, aa, bb, ans, s, i;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	a = b = -1, s = ans = 1;
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &aa, &bb);
		if (aa == a && bb == b)
			s++, ans = max(ans, s);
		else
			a = aa, b = bb, s = 1;
	}
	
	printf("%d\n", ans);
	return 0;
}