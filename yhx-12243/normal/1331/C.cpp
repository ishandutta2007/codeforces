#include <bits/stdc++.h>

int n, r = 0;

int main() {
	scanf("%d", &n);
	r |= (n >> 0 & 1) << 4;
	r |= (n >> 1 & 1) << 1;
	r |= (n >> 2 & 1) << 3;
	r |= (n >> 3 & 1) << 2;
	r |= (n >> 4 & 1) << 0;
	r |= (n >> 5 & 1) << 5;
	printf("%d\n", r);
	return 0;
}