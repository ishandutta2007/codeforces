#include <cstdio>
#include <algorithm>
#define MAXN 100005
int n, a[MAXN], b[MAXN];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) scanf("%d", b+i);
	if(a[1]!=b[1]||a[n]!=b[n]) return puts("No"), 0;
	for(int i=n; i; --i) a[i]-=a[i-1], b[i]-=b[i-1];
	std::sort(a+2, a+n+1), std::sort(b+2, b+n+1);
	for(int i=2; i<=n; ++i) if(a[i]!=b[i]) return puts("No"), 0;
	puts("Yes");
	return 0;
}