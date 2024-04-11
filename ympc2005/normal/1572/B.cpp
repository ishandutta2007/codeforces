#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n, a[N], b[N];

vector <int> p, ans;

void work_(int x) {
	ans.push_back(x);
	b[x] ^= b[x + 2], b[x + 2] = 0;
	b[x + 3] ^= b[x + 1], b[x + 1] = 0; 
}

void mov_(int l, int r) {
	if (l > 1) {
		while (l < r) {
			work_(l - 1);
			l += 2;
		} 
	} else if (r <= n) {
		while (l < r) {
			work_(r - 2);
			r -= 2;
		}
	}
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		p.clear(), ans.clear();
		
		for (int i = n; i; i--) {
			b[i] = a[i]^a[i - 1];
		}
	
		for (int i = 1; i <= n; i += 2) {
			if (b[i]) {
				p.push_back(i);
			}
		}
		
		if (p.size()&1) {
			if (n&1) {
				puts("NO");
				continue;
			}
			
			p.push_back(n + 1);
		}
		
		if (p.size() == 2 && p[0] == 1 && p[1] == n + 1) {
			puts("NO");
			continue;
		}
		
		for (int i = 0; i < (int) p.size(); i += 2) {
			mov_(p[i], p[i + 1]);
		}
		
		p.clear();
		
		for (int i = 2; i <= n; i += 2) {
			if (b[i]) {
				p.push_back(i);
			}
		}
		
		if (p.size()&1) {
			if (n&1) {
				p.push_back(n + 1);
			} else {
				puts("NO");
				continue;
			}
		}
		
		if (p.size() == 2 && p[0] == 1 && p[1] == n + 1) {
			puts("NO");
			continue;
		}
		
		for (int i = 0; i < (int) p.size(); i += 2) {
			mov_(p[i], p[i + 1]);
		}
		
		assert(ans.size() <= n);
		
		puts("YES");
		
		printf("%u\n", ans.size());
		
		for (int x : ans) {
			printf("%d ", x);
		}
		
		puts("");
	}
}