#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set <pair <int, int> > edge;
int ans[50005], n, m, a, b, i, j;

int main()
{
	scanf("%d %d", &n, &m);
	for (i = 1; i <= m; i++)
		scanf("%d %d", &a, &b), edge.insert(make_pair(a, b));
	for (i = 1; i <= n; i++)
	{
		ans[i] = i;
		for (j = i; j > 1; j--)
			if (edge.find(make_pair(ans[j - 1], ans[j])) != edge.end())
				swap(ans[j], ans[j - 1]);
			else
				break;
	}
	
	for (i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}