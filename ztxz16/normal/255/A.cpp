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

int n, i, x, s[5];

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &x), s[i % 3] += x;
	if (s[1] > s[2] && s[1] > s[0])
		printf("chest\n");
	if (s[2] > s[1] && s[2] > s[0])
		printf("biceps\n");
	if (s[0] > s[1] && s[0] > s[2])
		printf("back\n");
	return 0;
}