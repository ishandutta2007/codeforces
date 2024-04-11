#include <cstdio>
#include <cstring>

int main() {
	int n, k, a[1000];
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++) scanf("%d", a+i);
	int ret=0;
	for (int i=1; i<=n; i++) ret+=(a[i]>0 && a[i]>=a[k]);
	printf("%d\n", ret);
	return 0;
}