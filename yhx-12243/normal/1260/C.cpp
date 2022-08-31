#include <bits/stdc++.h>
#define gcd std::__gcd

const int N = 100054;

int A, B, K;

bool work() {
	int d;
	scanf("%d%d%d", &A, &B, &K);
	if (K == 1) return false;
	d = gcd(A, B), A /= d, B /= d;
	if (A > B) std::swap(A, B);
	return (A == 1 && B == 1) || (B - 2) / A + 1 < K;
}

int main() {
	int T;
	for (scanf("%d", &T); T; --T) puts(work() ? "OBEY" : "REBEL");
	return 0;
}