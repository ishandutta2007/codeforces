#include <bits/stdc++.h>
using namespace std;

int n, T;

int main() {
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			printf("%d ", i + 1);
		}

		puts("");
	}
}