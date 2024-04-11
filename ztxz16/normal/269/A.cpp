#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

struct node
{
	ll k, a;
}a[100005];

ll cmp(node a, node b)
{
	return a.k < b.k;
}

ll n, i, Now, Now2, xx, xxx;

int main()
{
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++)
		scanf("%I64d %I64d", &a[i].k, &a[i].a);
	sort(a + 1, a + n + 1, cmp);
	Now = a[1].a, Now2 = a[1].k;
	for (i = 2; i <= n; i++)
	{
		xx = 1;
		while (Now2 < a[i].k && xx * a[i].a < Now)
			Now2++, xx *= 4;
		if (xx * a[i].a >= Now)
			Now2 = a[i].k, Now = a[i].a;
		else
		{
			xxx = (Now - xx * a[i].a) / xx;
			if ((Now - xx * a[i].a) % xx > 0)
				xxx++;
			Now = a[i].a + xxx;
			Now2 = a[i].k;
		}
	}
	
	if (Now == 1)
		printf("%I64d\n", Now2 + 1);
	else
	{
		xx = 1;
		while (xx < Now)
			xx *= 4, Now2++;
		printf("%I64d\n", Now2);
	}
	
	return 0;
}