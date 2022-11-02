#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int n, sum[maxn + 3];
char s[maxn + 3], ans[maxn + 3];

void query(int l, int r) {
	printf("? %d %d\n", l, r);
	fflush(stdout);
}

void answer() {
	printf("! %s\n", ans + 1);
	fflush(stdout);
}

int main() {
	scanf("%d", &n);
	if (n <= 3) {
		for (int i = 1; i <= n; i++) {
			query(i, i);
			scanf("%s", s + 1);
			ans[i] = s[1];
		}
	} else {
		int m = n / 2;
		query(1, m);
		for (int i = 1; i <= m * (m + 1) / 2; i++) {
			scanf("%s", s + 1);
			string str = s + 1;
			for (int j = 1; j <= str.length(); j++) {
				sum[str.length()] += s[j] - 'a';
			}
		}
		query(2, m);
		for (int i = 1; i <= m * (m - 1) / 2; i++) {
			scanf("%s", s + 1);
			string str = s + 1;
			for (int j = 1; j <= str.length(); j++) {
				sum[str.length()] -= s[j] - 'a';
			}
		}
		for (int i = m; i; i--) {
			sum[i] -= sum[i - 1];
			ans[i] = sum[i] + 'a';
		}
		query(1, n);
		for (int i = 1; i <= n * (n + 1) / 2; i++) {
			scanf("%s", s + 1);
			string str = s + 1;
			if (str.length() > m) {
				for (int j = 1; j <= str.length(); j++) {
					sum[str.length()] += s[j] - 'a';
				}
			}
		}
		for (int i = m + 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sum[i] -= sum[j] * min(j, n - i + 1);
			}
		}
		for (int i = m + 1; i <= n; i++) {
			sum[i] -= sum[i + 1];
		}
		for (int i = m + 1; i <= n; i++) {
			ans[i] = sum[i] - (i == m + 1 ? 0 : sum[i - 1]) + 'a';
		}
	}
	answer();
	return 0;
}