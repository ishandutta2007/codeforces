#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, a[100005], Ans;

int main()
{
	n = 4;
	for (i = 1; i <= 4; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (i = 2; i <= n; i++)
		if (a[i] == a[i - 1])
			Ans++;
	printf("%d\n", Ans);
	return 0;
}