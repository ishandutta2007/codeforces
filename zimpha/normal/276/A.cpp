#include <cstdio>

int main() {
	int n, k, ret=-1e9;
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; i++) {
		int f, t; scanf("%d%d", &f, &t);
		if (t>k) f-=(t-k);
		if (f>ret) ret=f;
	}
	printf("%d\n", ret);
	return 0;
}