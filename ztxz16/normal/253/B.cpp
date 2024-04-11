#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, l, r, a[100005];
int Now, Min = 1616161616;

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	r = 1;
	for (l = 1; l <= n; l++)
	{
		while ((a[l] << 1) >= a[r] && r <= n)
			r++;
		r--;
		Now = (l - 1) + (n - r);
		if (Now < Min)
			Min = Now;
	}
	
	printf("%d\n", Min);
	return 0;
}