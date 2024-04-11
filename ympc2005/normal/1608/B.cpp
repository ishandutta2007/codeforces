#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a, b, c, T, l, r;

void L_() {
	printf("%d ", l++);
} 

void R_() {
	printf("%d ", r--);
}

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d%d%d", &n, &a, &b);

		if (abs(a - b) > 1 || a + b > n - 2) {
			puts("-1");
			continue;
		}

		c = n - a - b;

		if (!a && !b) {
			for (int i = 1; i <= n; i++) {
				printf("%d ", i);
			}

			puts("");
			continue;
		}

		l = 1, r = n;

		if (a > b) {
			L_(), R_();

			for (int i = 1; i <= b; i++) {
				L_(), R_();
			}

			for (int i = 1; i < c; i++) {
				R_();
			}

			puts("");
		} else if (a < b) {
			R_(), L_();

			for (int i = 1; i <= a; i++) {
				R_(), L_();
			}

			for (int i = 1; i < c; i++) {
				L_();
			}

			puts("");
		} else {
			L_();

			for (int i = 1; i <= a; i++) {
				R_(); L_();
			}

			for (int i = 1; i < c; i++) {
				L_();
			}

			puts("");
		}
	}
}