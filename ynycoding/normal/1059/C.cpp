#include <cstdio>

int n, now, p=1;
int main()
{
	scanf("%d", &n);
	now=n;
	while(now)
	{
		if(now==3)
		{
			return printf("%d %d %d", p, p, p*3), 0;
		}
		for(int i=1; i<=now-now/2; ++i) printf("%d ", p);
		now/=2;
		p*=2;
	}
	return 0;
}