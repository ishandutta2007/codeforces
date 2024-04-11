#include <cstdio>

int main() {
	int n, m, ret=0;
	scanf("%d%d", &n, &m);
	for (int a=0; a<=n; a++)
		for (int b=0; b<=n; b++)
			if (a*a+b==n && a+b*b==m) ret++;
	printf("%d\n", ret);
	return 0;
}