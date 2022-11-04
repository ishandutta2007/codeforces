#include <stdio.h>
#include <stdlib.h>

long long n, d, i, r, a[100005];
long long Ans;

int main()
{
	scanf("%I64d %I64d", &n, &d);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	r = 1;
	for (i = 1; i <= n; i++)
	{
		while (r <= n && a[r] - a[i] <= d)
			r++;
		r--;
		if (r - i >= 2)
		{
			Ans += ((r - i) * (r - i - 1) / 2);
		}
	}
	
	printf("%I64d\n", Ans);
	return 0;
}