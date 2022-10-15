#include <bits/stdc++.h>

typedef long long ll;
typedef double ff;

const int kMaxN = 1e6 + 5;

int n, st[kMaxN], top = 0; ll a[kMaxN], s[kMaxN];

ff Cal(int x, int y) { return (ff)(s[y] - s[x]) / (y - x); }
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a + i), s[i] = s[i - 1] + a[i];
	for(int i = 0; i <= n; ++i) {
		for(; top > 1 && Cal(st[top], st[top - 1]) > Cal(i, st[top - 1]); --top);
		st[++top] = i;
	}
	for(int i = 2; i <= top; ++i) {
		ff adv = Cal(st[i], st[i - 1]);
		for(int j = st[i - 1] + 1; j <= st[i]; ++j)
			printf("%.10llf\n", adv);
	}
	return 0;
}