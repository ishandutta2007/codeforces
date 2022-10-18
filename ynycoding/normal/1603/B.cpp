#include <cstdio>
#include <algorithm>
int T, x, y;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &x, &y);
		if(x>y) printf("%d\n", x+y);
		else
		{
			int n=(y%x)/2;
			printf("%d\n", y-n);
		}
	}
	return 0;
}