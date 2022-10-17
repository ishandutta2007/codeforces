#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int n, p[N], a[N];
int query() {
	printf("? ");
	for (int i = 1; i <= n; ++i)
		printf("%d%c", a[i], " \n"[i == n]);
	fflush(stdout);
	int x;
	scanf("%d", &x);
	return x;
}
void answer() {
	printf("! ");
	for (int i = 1; i <= n; ++i)
		printf("%d%c", p[i], " \n"[i == n]);
	fflush(stdout);
}
int main() {
	scanf("%d", &n);
	fill(a + 1, a + n, n);
	p[n] = 1;
	for (int i = 1; i < n; ++i) {
		a[n] = i;
		int x = query();
		if (x > 0) {
			p[n] = n + 1 - i;
			break;
		}
	}
	a[n] = n + 1 - p[n];
	for (int i = 1; i <= n; ++i) {
		int goal = n + 1 - i;
		if (p[n] == goal) continue;
		fill(a + 1, a + n, i);
		int x = query();
		p[x] = goal;
	}
	answer();
	return 0;
}