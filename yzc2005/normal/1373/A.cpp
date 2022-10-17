#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%d%d%d", &a, &b, &c);
		if(1ll * a * b <= c) {
			if(b == 1) puts("-1 -1");
			else puts("1 -1");
		} else {
			if(a < c) printf("1 %d\n", b);
			else printf("-1 %d\n", b);
		}
	}
	return 0;
}