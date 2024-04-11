#include <bits/stdc++.h>
using namespace std;

int n, m, q;
char s[50][20], t[50][20];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%s", t[i] + 1);
	}
	scanf("%d", &q);
	for (int x; q --> 0; ) {
		scanf("%d", &x), x--;
		printf("%s%s\n", s[x % n + 1] + 1, t[x % m + 1] + 1);
	}
	return 0;
}