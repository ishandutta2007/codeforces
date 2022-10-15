#include <bits/stdc++.h>

bool cmp(int a, int b) { return a > b; }

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int a[4], cnt = 0;
		scanf("%d%d%d", a + 0, a + 1, a + 2);
		std::sort(a, a + 3, cmp);
		if(a[0] >= 1) ++cnt, --a[0];
		if(a[1] >= 1) ++cnt, --a[1];
		if(a[2] >= 1) ++cnt, --a[2];
		if(a[0] >= 1 && a[1] >= 1) ++cnt, --a[0], --a[1];
		if(a[0] >= 1 && a[2] >= 1) ++cnt, --a[0], --a[2];
		if(a[1] >= 1 && a[2] >= 1) ++cnt, --a[2], --a[1];
		if(a[0] >= 1 && a[1] >= 1 && a[2] >= 1) ++cnt, --a[2], --a[1], --a[0];
		printf("%d\n", cnt);
	}
	return 0;
}