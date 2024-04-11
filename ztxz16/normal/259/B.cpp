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

int i, j, s, a[5][5];

int main()
{
	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			scanf("%d", &a[i][j]), s += a[i][j];
	s >>= 1;
	a[1][1] = s - a[2][1] - a[3][1];
	a[2][2] = s - a[1][2] - a[3][2];
	a[3][3] = s - a[1][3] - a[2][3];
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j < 3; j++)
			printf("%d ", a[i][j]);
		printf("%d\n", a[i][j]);
	}
	
	return 0;
}