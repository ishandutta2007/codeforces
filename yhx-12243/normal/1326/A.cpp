#include <bits/stdc++.h>

const int N = 100054;

int n;

void work() {
	int i;
	scanf("%d", &n);
	if (n == 1) {puts("-1"); return;}
	for (i = 1; i < n; ++i) putchar(57);
	putchar(56), putchar(10);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}