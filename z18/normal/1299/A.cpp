#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, a[maxn + 3], cnt[50];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		for (int j = 0; j <= 30; j++) {
			if (a[i] >> j & 1) {
				cnt[j]++;
			}
		}
	}
	int ans = -1, p = 0;
	for (int i = 1; i <= n; i++) {
		int res = 0;
		for (int j = 0; j <= 30; j++) {
			if ((a[i] >> j & 1) && cnt[j] == 1) {
				res |= 1 << j;
			}
		}
		if (res > ans) {
			ans = res, p = i;
		}
	}
	printf("%d ", a[p]);
	for (int i = 1; i <= n; i++) if (i != p) {
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}