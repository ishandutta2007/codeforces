#include <cstdio>
#include <algorithm>
#define MAXN 200005
int n, z, a[MAXN];
bool check(int x)
{
	if(x*2>n) return 0;
	for(int i=1; i<=x; ++i)
	{
		if(a[n-x+i]-a[i]<z) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d%d", &n, &z);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	std::sort(a+1, a+n+1);
	int l=0, r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%d\n", l);
	return 0;
}