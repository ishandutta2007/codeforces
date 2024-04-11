#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, tot, a, b, Min, Ans;
int x[100005], s[100005];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	tot = 0;
	for (int i = 1; i <= n; i++)
		if (i == 1 || x[i] != x[i - 1])
			s[++tot] = x[i];
	scanf("%d %d", &a, &b);
	Ans = 0;
	while (a > b)
	{
		Min = a - 1;
		int tot2 = 0;
		for(int i = 1; i <= tot; i++)
			if ((a - a % s[i]) >= b)
				s[++tot2] = s[i];
		tot = tot2; 
		for (int i = 1; i <= tot; i++)
			if ((a - a % s[i]) < Min)
				Min = (a - a % s[i]);
		a = Min;
		//printf("%d\n", a);
		Ans++;
	}
	
	printf("%d\n", Ans);
	return 0;
}