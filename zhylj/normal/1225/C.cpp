#include <bits/stdc++.h>

int main() {
	int n, p; bool flag = false;
	scanf("%d%d", &n, &p);
	for(int i = 1; i <= 1e6 && !flag; ++i) {
		int x = n - p * i, cnt = 0;
		if(x < 0) continue;
		for(int j = 0; j <= 31; ++j)
			if((x >> j) & 1) ++cnt;
		if(cnt <= i && x >= i)
			printf("%d", i), flag = true;
	}
	if(!flag) printf("-1");
	return 0;
}