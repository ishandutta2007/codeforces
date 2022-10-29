#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
	int a, b, c;
	int x, y, z;
	scanf("%d%d%d", &a, &b, &c);
	x=a+b-c; y=b+c-a; z=a-b+c;
	if (x>=0&&y>=0&&z>=0&&x%2==0&&y%2==0&&z%2==0) printf("%d %d %d\n", x/2, y/2, z/2);
	else puts("Impossible");
}