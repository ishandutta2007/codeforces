#include <cstdio>
#include <algorithm>
#define MAXN 300005
int n, k, a[MAXN], ans;
int main()
{
	scanf("%d%d", &n, &k);
	if(n==1) return puts("0"), 0;
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	ans=a[n]-a[1];
	for(int i=n; i>=2; --i) a[i]-=a[i-1];
	std::sort(a+2, a+n+1);
	for(int i=n; i>n-k+1; --i) ans-=a[i];
	printf("%d", ans);
	return 0;
}