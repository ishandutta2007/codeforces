#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map <int, int> a;
int x[1005];
int n, i, Ans, tag;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &x[i]), a[x[i]]++;
	for (i = 1; i <= n; i++)
	{
		if (x[i] == 0)
			continue;
		if (a[x[i]] == 2)
			Ans++;
		if (a[x[i]] > 2)
			tag = 1;
	}
	
	if (tag == 1)
		printf("-1\n");
	else
		printf("%d\n", (Ans >> 1));
	return 0;
}