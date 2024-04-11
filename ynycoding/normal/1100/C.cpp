#include <cstdio>
#include <cmath>
#define db double
int n, r;
db Pi=acos(-1.0), rad, srad;
int main()
{
	scanf("%d %d", &n, &r);
	rad=Pi/(db)n;
	srad=sin(rad);
	printf("%.7lf", srad*(db)r/(1.0-srad));
	return 0;
}