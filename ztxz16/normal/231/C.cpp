#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

long long n, k, i, l, r, mid, Now;
long long a[100005], s[100005], Ans, sel;

int main()
{
	scanf("%I64d %I64d", &n, &k);
	for (i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	sort(a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for (i = 1; i <= n; i++)
	{
		l = 1, r = i;
		while (l < r)
		{
			mid = ((l + r) >> 1);
			if (((i - mid + 1) * a[i]) - (s[i] - s[mid - 1]) <= k)
				r = mid;
			else
				l = mid + 1;
		}
		
		Now = i - l + 1;
		if (Now > Ans)
			Ans = Now, sel = a[i];
	}
	
	printf("%I64d %I64d\n", Ans, sel);
	return 0;
}