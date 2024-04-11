#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
	scanf("%d", &T);
	while (T --> 0) {
		scanf("%d", &n);
		if (n == 1) {
			puts("-1");
		} else {
			putchar('8');
			for (int i = 1; i < n; i++) putchar('9');
			puts("");
		}
	}
	return 0;
}