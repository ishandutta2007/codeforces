#include <bits/stdc++.h>
#define lg2 std::__lg

const int N = 100054;

int n;
int a[N];

void work() {
	int i, last, incr;
	scanf("%d", &n);
	for (i = 0; i < n; ++i) scanf("%d", a + i);
	last = a[0], incr = 0;
	for (i = 1; i < n; ++i)
		if (last > a[i])
			incr = std::max(incr, last - a[i]);
		else last = a[i];
	printf("%d\n", incr ? lg2(incr) + 1 : 0);
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) work();
	return 0;
}