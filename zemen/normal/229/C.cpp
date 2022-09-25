#include <stdio.h>
#include <vector>

int d[1000001];

int main() {
	int n, m, u, v;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &u, &v);
		--u;
		--v;
		d[u]++;
		d[v]++;
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += d[i] * (n - 1 - d[i]);
	}
	sum /= 2;
	long long all = (((long long) n) * ((long long) (n - 1)) * ((long long) (n - 2))) / 6;
	printf("%I64d", all - sum);
}