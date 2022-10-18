#include <cstdio>
#define db double
db h, l;
int main()
{
	scanf("%lf%lf", &h, &l);
	printf("%.8f\n", (l*l-h*h)/(2.0*h));
	return 0;
}