#include <cstdio>
#include <cmath>
#include <algorithm>
const int N=100005;
int n, k;
inline int ask(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
inline void ans(int x)
{
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}
int main()
{
	scanf("%d%d", &n, &k);
	int x=1, d=sqrt(n);
	while(d>1&&n%d==0) --d;
	while(1)
	{
		int t=ask(x);
		if(t>k)
		{
			while(1)
			{
				--x;
				if(!x) x=n;
				t=ask(x);
				if(t==k) ans(x);
			}
		}
		if(t<k)
		{
			while(1)
			{
				++x;
				if(x>n) x=1;
				t=ask(x);
				if(t==k) ans(x);
			}
		}
		x+=d;
		x%=n;
		if(!x) x=n;
	}
	return 0;
}