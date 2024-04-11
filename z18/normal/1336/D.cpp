#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int n, m, a[maxn + 3], b[maxn + 3], res[maxn + 3];

void query(int x) {
	printf("+ %d\n", x), fflush(stdout);
	++m, scanf("%d %d", &a[m], &b[m]);
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	scanf("%d %d %d", &n, &a[0], &b[0]);
	for (int i = n - 1; i >= 3; i--) query(i);
	query(1), query(2), query(1);
	for (int i = n; i; i--) a[i] -= a[i - 1], b[i] -= b[i - 1];
	for (int i = 0; i <= n; i++) if (i * (i + 1) / 2 == a[n]) res[1] = i;
	res[2] = b[n - 2] / gcd(b[n - 2], b[n]);
	res[3] = b[n] - b[n - 2] - 1;
	res[4] = (b[n - 1] - (res[1] + 1) * (res[3] + 1)) / (res[3] + 1) - (n != 4);
	for (int i = 3; i <= n - 2; i++) {
		int x = b[n - i];
		res[i + 2] = (x - res[i - 2] * res[i - 1] - res[i - 1] * (res[i + 1] + 1)) / (res[i + 1] + 1) - (i != n - 2);
	}
	putchar('!');
	for (int i = 1; i <= n; i++) printf(" %d", res[i]);
	puts("");
	return 0;
}