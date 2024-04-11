#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647

using namespace std;

int n, i, x, s[5], s2;

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		s[x & 1]++;
		s2 += (x & 1);
	}
	
	printf("%d\n", s[s2 & 1]);
	return 0;
}