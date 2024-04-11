#include <cstdio>
#include <algorithm>
#define MAXN 1005
int n, a[MAXN], tag[MAXN];
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	std::sort(a+1, a+n+1);
	for(int i=1; i<=n; i+=2) printf("%d ", a[i]), tag[i]=1;
	for(int i=n; i; --i) if(!tag[i]) printf("%d ", a[i]);
	return 0;
}