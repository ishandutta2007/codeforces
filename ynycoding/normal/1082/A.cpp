#include <cstdio>
#include <algorithm>
int t, n, x, y, d;
inline int cll(int a, int b) { return a%b?a/b:a/b+1; }
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d", &n, &x, &y, &d);
		if((y-x)%d==0) printf("%d\n", y-x<0?(x-y)/d:(y-x)/d);
		else if((y-1)%d==0)
		{
			if((n-y)%d==0) printf("%d\n", std::min(cll(n-y, d)+cll(n-x, d), cll(y-1, d)+cll(x-1, d)));
			else printf("%d\n", cll(y-1, d)+cll(x-1, d));
		}
		else if((n-y)%d==0) printf("%d\n", cll(n-y, d)+cll(n-x, d));
		else puts("-1");
	}
	return 0;
}