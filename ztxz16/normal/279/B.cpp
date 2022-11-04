#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int ans, n, t, s[1000005], l, r, i;

int main()
{
	scanf("%d %d", &n, &t);
	for (i = 1; i <= n; i++)
		scanf("%d", &s[i]);
	for (i = 1; i <= n; i++)
		s[i] += s[i - 1];
	r = 0;
	for (l = 1; l <= n; l++)
	{
		while (r <= n && s[r] - s[l - 1] <= t)
			r++;
		r--;
		ans = max(ans, r - l + 1);
	}
	
	printf("%d\n", ans);
	return 0;
}