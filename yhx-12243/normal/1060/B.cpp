#include <bits/stdc++.h>
#define N 120

int n, ans;
char s[N];

int main() {
	int i;
	scanf("%s", s); n = strlen(s);
	ans = (n - 1) * 9; --*s;
	for (i = n - 1; i && s[i] == '9'; --i) s[i] = '0';
	++s[i];
	for (i = 0; i < n; ++i) ans += s[i] & 15;
	printf("%d\n", ans);
	return 0;
}