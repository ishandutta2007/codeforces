#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, j, sum, Now, Ans, s[105], x;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &x), s[i] = s[i - 1] + x;
	for (i = 1; i <= n; i++)
		for (j = i; j <= n; j++)
		{
			sum = j - i + 1;
			Now = s[i - 1] + s[n] - s[j] + sum - (s[j] - s[i - 1]);
			Ans = max(Now, Ans);
		}
		
	printf("%d\n", Ans);
	return 0;
}