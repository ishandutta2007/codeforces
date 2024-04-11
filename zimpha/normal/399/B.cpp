#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	long long ret = 0;
	char st[10000]; scanf("%s", st);
	for (int i = 0; i < n; ++ i) {
		if (st[i] == 'B') ret |= 1ll << i;
	}
	printf("%I64d\n", ret);
	return 0;
}