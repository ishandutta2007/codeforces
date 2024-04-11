#include <bits/stdc++.h>

const int N = 1054;

int n;
char s[N];
int L = 0, ans[N];

int main() {
	int i, j;
	scanf("%s", s), n = strlen(s), i = 0, j = n - 1;
	for (; i < j; ) {
		for (; i < j && s[i] == 41; ++i);
		for (; i < j && s[j] == 40; --j);
		if (s[i] == 40 && s[j] == 41)
			ans[L++] = i++, ans[L++] = j--;
		else break;
	}
	if (!L) return puts("0"), 0;
	std::sort(ans, ans + L);
	printf("1\n%d\n", L);
	for (i = 0; i < L; ++i) printf("%d%c", ans[i] + 1, i==L-1?10:32);
	return 0;
}