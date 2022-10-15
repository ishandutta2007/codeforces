#include <bits/stdc++.h>

const int kMaxN = 1e5 + 5;

int t, n; char s[kMaxN];

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		int cnt = 0;
		scanf("%s", s + 1);
		for(int i = 1; i <= n; ++i) {
			if((s[i] - 48) % 2 == 0) s[i] = -1;
			else ++cnt;
		}
		if(cnt <= 1) printf("-1\n");
		else {
			for(int i = 1, cur = 0; i <= n && cur < 2; ++i) {
				if(~s[i]) printf("%c", s[i]), ++cur;
			}
			printf("\n");
		}
	}
	return 0;
}