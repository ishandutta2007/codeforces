#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
int n, a[maxn + 3];

int _abs(int x) {
	return x < 0 ? -x : x;
}

int main() {
	scanf("%d", &n);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		cnt += _abs(a[i]) & 1;
	}
	int cur = 0;
	for (int i = 1, t; i <= n; i++) {
		if (a[i] & 1) {
			cur++;
			t = a[i] / 2;
			if (t * 2 + 1 != a[i]) {
				t--;
			}
			if (cur * 2 <= cnt) {
				t++;
			}
		} else {
			t = a[i] / 2;
		}
		printf("%d\n", t);
	}
	return 0;
}