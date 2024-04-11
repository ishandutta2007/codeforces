#include <bits/stdc++.h>

const int kMaxN = 1e6 + 5;
const int kInf = 0x3f3f3f3f;

int c[kMaxN], a[kMaxN], minn = kInf;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		memset(c, 0, sizeof(c));
		int n, k, d; minn = kInf;
		scanf("%d%d%d", &n, &k, &d);
		for(int i = 1; i <= n; ++i)
			scanf("%d", a + i);
		int cnt = 0;
		for(int i = 1; i <= d; ++i) {
			if(!c[a[i]]) ++cnt;
			++c[a[i]];
		}
		minn = cnt;
		for(int i = 1; i < n - d + 1; ++i) {
			--c[a[i]];
			if(!c[a[i]]) --cnt;
			if(!c[a[i + d]]) ++cnt;
			++c[a[i + d]];
			//printf("[%d, %d]: %d\n", i + 1, i + d, cnt);
			minn = std::min(minn, cnt);
		}
		printf("%d\n", minn);
	}
	return 0;
}