#include <bits/stdc++.h>

typedef long long ll;

const int kN = 1e6 + 5;

char s[kN];

int main() {
	int n, top = 0, lst = 0, ans = 0;
	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '(') {
			++top;
		} else --top;
		//printf("%d %d\n", top, lst);
		if(s[i] == '(' && top == 0) ans += lst + 1, lst = 0;
		else if(top < 0) ++lst;
		else lst = 0;
	}
	if(top != 0) printf("-1");
	else printf("%d", ans);
	return 0;
}