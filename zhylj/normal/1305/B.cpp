#include <bits/stdc++.h>

const int kN = 1e3 + 5;

char s[kN]; int top = 0, q[kN], p[kN];

int main() {
	int n;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; ++i) {
		q[i] = q[i - 1] + (s[i] == '(');
		p[i] = p[i - 1] + (s[i] == ')');
	}
	int ans = 0x3f3f3f3f, m;
	for(int i = 0; i <= n; ++i) {
		int tmp = q[i] + p[n] - p[i];
		if(q[i] == p[n] - p[i]) m = i, ans = tmp;
	}
	if(ans == 0) printf("0");
	else {
		printf("%d\n%d\n", 1, ans);
		for(int i = 1; i <= m; ++i)
			if(s[i] == '(') printf("%d ", i);
		for(int i = m + 1; i <= n; ++i)
			if(s[i] == ')') printf("%d ", i);
	}
	return 0;
}