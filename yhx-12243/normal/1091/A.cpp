#include <bits/stdc++.h>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", std::min(std::min(a + 1, b), c - 1) * 3);
	return 0;
}