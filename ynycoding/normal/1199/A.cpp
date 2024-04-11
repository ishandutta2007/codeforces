#include <cstdio>
#define MAXN 100005
int n, a[MAXN], x, y;
int main()
{
	scanf("%d%d%d", &n, &x, &y);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i)
	{
		bool flag=1;
		for(int j=i-1; j>=i-x&&j; --j) if(a[j]<=a[i]) { flag=0; break; }
		for(int j=i+1; j<=i+y&&j<=n; ++j) if(a[j]<=a[i]) { flag=0; break; }
		if(flag) return printf("%d\n", i), 0;
	}
	return 0;
}