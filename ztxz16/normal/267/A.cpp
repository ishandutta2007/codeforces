#include <stdio.h>
#include <stdlib.h>

int test, a, b;
long long Ans;

void gcd(int a, int b);

int main()
{
	scanf("%d", &test);
	while (test > 0)
	{
		test--;
		scanf("%d %d", &a, &b);
		Ans = 0;
		if (a > b)
			gcd(a, b);
		else
			gcd(b, a);
		printf("%I64d\n", Ans);
	}
	
	return 0;
}

void gcd(int a, int b)
{
	if (b == 0)
		return;
	Ans += a / b;
	gcd(b, a % b);
	return;
}