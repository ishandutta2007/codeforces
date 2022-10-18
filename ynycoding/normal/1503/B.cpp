#include <cstdio>
#include <algorithm>
#define N 105
int n, s[N][N], x, ax=1, ay=1, bx=1, by=2;
inline int gid(int x, int y) { return (x-1)*n+y; }
inline void put(int x, int y, int z) { printf("%d %d %d\n", x, y, z); fflush(stdout); }
int main()
{
	scanf("%d", &n);
	int T=n*n;
	while(T--)
	{
		scanf("%d", &x);
		if(gid(ax, ay)>n*n)
		{
			put((x==2?3:2), bx, by);
			by+=2;
			if(by>n) ++bx, by=(n&1)?by-n:((by-n-1)^1)+1;
		}
		else if(gid(bx, by)>n*n)
		{
			put((x==1?3:1), ax, ay);
			ay+=2;
			if(ay>n) ++ax, ay=(n&1)?ay-n:((ay-n-1)^1)+1;
		}
		else
		{
			if(x==1)
			{
				put(2, bx, by);
				by+=2;
				if(by>n) ++bx, by=(n&1)?by-n:((by-n-1)^1)+1; 
			}
			else
			{
				put(1, ax, ay);
				ay+=2;
				if(ay>n) ++ax, ay=(n&1)?ay-n:((ay-n-1)^1)+1;
			}
		}
	}
	return 0;
}