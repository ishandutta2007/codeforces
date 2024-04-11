#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, i, Ans;

int main()
{
	scanf("%d", &n);
	for (i = 1; i < n; i++)
		Ans += ((n - i) * i);
	Ans += n;
	printf("%d\n", Ans);
	return 0;
}