#include <bits/stdc++.h>

const int N = 150054;

int n;
char s[N];
int rr[N];

int main() {
	int i, T, ans;
	for (scanf("%d", &T); T; --T) {
		scanf("%s", s), n = strlen(s), ans = 0, s[n] = s[n + 1] = s[n + 2] = s[n + 3] = 0;
		for (i = 2; i < n; ++i)
			if (!memcmp(s + i - 2, "one", 3) || !memcmp(s + i - 2, "two", 3)) {
				if (!memcmp(s + i - 2, "twone", 5)) s[i] = 0, rr[ans++] = i + 1;
				else s[i - 1] = 0, rr[ans++] = i;
			}
		printf("%d\n", ans);
		for (i = 0; i < ans; ++i) {
			if (i) putchar(32);
			printf("%d", rr[i]);
		}
		putchar(10);
	}
	return 0;
}