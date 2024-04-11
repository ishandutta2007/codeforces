#include <cstdio>

int main() {
	int n, tot=0, ret=0;
	scanf("%d", &n);
	for (int i=0, a, b; i<n; i++) {
		scanf("%d%d", &a, &b);
		tot+=-a+b;
		if (tot>ret) ret=tot;
	}
	printf("%d\n", ret);
	return 0;
}