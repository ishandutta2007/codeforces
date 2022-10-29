#include <cstdio>

int main() {
	int n, a, b, c, ret=0;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d%d", &a, &b, &c);
		ret+=(a+b+c>=2);
	}
	printf("%d\n", ret);
	return 0;
}