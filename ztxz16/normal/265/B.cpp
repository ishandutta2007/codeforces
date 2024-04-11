#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, x, i, Now, Ans;

int main()
{
	scanf("%d", &n);
	scanf("%d", &x);
	Ans += (x + 1);
	Now = x;
	for (i = 2; i <= n; i++)
	{
		scanf("%d", &x);
		if (x > Now)
			Ans += (x - Now + 2);
		else
			Ans += (Now - x + 2);
		Now = x;
	}
	
	printf("%d\n", Ans);
	return 0;
}