#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6;
int n, m, p[maxn + 3];
char s[maxn + 3];

int main() {
	scanf("%d %s", &n, s + 1);
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') cur++;
		else cur--;
		if (cur == 0) {
			p[++m] = i;
		}
	}
	if (cur != 0) {
		puts("-1");
		return 0;
	} 
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		if (s[p[i]] == '(') {
			ans += p[i] - p[i - 1];
		}
	}
	printf("%d\n", ans);
	return 0;
}