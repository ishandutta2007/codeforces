#include <cstdio>
#include <cstring>

int main() {
	int n, id=1; scanf("%d", &n);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n/2; j++, id++) {
			if (j!=1) putchar(' ');
			printf("%d %d", id, n*n-id+1);
		}
		puts("");
	}
	return 0;
}