#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#define eps 1e-10

using namespace std;

struct point
{
	double a, b, c;
}a[100005];

double Ans, s;
int n, i;

inline int bj(double a, double b)
{
	if (a - b < eps && a - b > 0 - eps)
		return 0;
	if (a < b)
		return -1;
	return 1;
}

inline int cmp(point a, point b)
{
	return (bj((a.c * (100 - b.b)), (b.c * (100 - a.b))) == 1);
}

int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%lf %lf", &a[i].a, &a[i].b), a[i].c = (a[i].a * a[i].b / 100), Ans += a[i].a;
	sort(a + 1, a + n + 1, cmp);
	for (i = 1; i <= n; i++)
	{
		Ans += (1.0 - a[i].b / 100) * s;
		s += a[i].c;
	}
	
	printf("%.10lf\n", Ans);
	return 0;
}