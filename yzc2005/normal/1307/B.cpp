#include <bits/stdc++.h>
using namespace std;

int main() {
	int _, n, x, y, mx;
	for(scanf("%d", &_); _; --_) {
		scanf("%d%d", &n, &x);
		bool flg = 0; mx = 0;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &y);
			mx = max(mx, y);
			if(y == x && !flg) {
				puts("1");
				flg = 1;
			}
		}
		if(!flg) printf("%d\n", max(2, (int)ceil(x * 1.0 / mx)));
 	}	
 	return 0;
}