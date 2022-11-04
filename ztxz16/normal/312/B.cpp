#include <stdio.h>
#include <stdlib.h>

double a, b, c, d;

int main()
{
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("%.10lf\n", a / b / (1 - (1 - a / b) * (1 - c / d)));
	return 0;
}