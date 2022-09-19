# include <cstdio>
# include <set>
using namespace std;
int main()
{
	int h1, h2, a, b;
	scanf("%d%d%d%d", &h1, &h2, &a, &b);
	int time = 0;
	if (a <= b)
	{
		if (h2 - h1 > 8 * a)
			printf("-1\n");
		else
			printf("0\n");
	}
	else
	{
		int time = 4;
		while (h1 < h2)
		{
			if (time % 24 < 12)
				h1 += a;
			else
				h1 -= b;
			time ++;
		}
		printf("%d\n", time / 24);
	}
}