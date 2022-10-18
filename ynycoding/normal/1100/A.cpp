#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAXN 101
int n, a[MAXN], k, ans;
int get(int b, int c)
{
	int ret=0;
	for(int i=1; i<=n; ++i) if(i%c!=b%c) ret+=a[i];
	return abs(ret);
}
int main()
{
	scanf("%d %d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) ans=std::max(ans, get(i, k));
	printf("%d", ans);
	return 0;
}