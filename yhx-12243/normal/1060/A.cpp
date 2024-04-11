#include <bits/stdc++.h>
#define N 120

int n, fy = 0;
char s[N];

int main() {
	int i;
	scanf("%d%s", &n, s);
	for (i = 0; i < n; ++i) fy += s[i] == 56;
	printf("%d\n", std::min(fy, n / 11));
	return 0;
}