#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, q, ans;

char s[N], t[3];

bool chk_(int x) {
	if (!(1 <= x && x + 2 <= n)) {
		return 0;
	}
	
	return s[x] == 'a' && s[x + 1] == 'b' && s[x + 2] == 'c';
}

int main() {
	scanf("%d%d%s", &n, &q, s + 1);
	
	for (int i = 1; i <= n - 2; i++) {
		ans += chk_(i);
	}
	
	for (int x, i = 1; i <= q; i++) {
		scanf("%d%s", &x, t + 1);
		
		for (int j = 0; j < 3; j++) {
			ans -= chk_(x - j);
		}
		
		s[x] = t[1];
		
		for (int j = 0; j < 3; j++) {
			ans += chk_(x - j);
		}
		
		printf("%d\n", ans);
	}
}