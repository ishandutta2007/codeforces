#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXN=100000+10;

int a[MAXN];
int n;

int main()
{
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	int ret=1;
	for (int i=1; i<n; i++)
		if (a[i]!=a[i-1]) ret++;
	printf("%d\n", ret);
	return 0;
}