#include <bits/stdc++.h>

const int kMaxN = 233;

char a[kMaxN], b[kMaxN], c[kMaxN];

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		bool flag = true;
		scanf("%s%s%s", a + 1, b + 1, c + 1);
		int n = strlen(a + 1);
		for(int i = 1; i <= n; ++i) {
			if(c[i] != b[i] && c[i] != a[i]) {
				flag = false; break;
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	}
	return 0;
}