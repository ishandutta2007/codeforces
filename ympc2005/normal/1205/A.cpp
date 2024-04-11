#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], T;

int main() {
	T = 1;
	
	while (T--) {
		scanf("%d", &n);
		
		if (n%2 == 0) {
			puts("NO");
			continue;
		}
		
		puts("YES");
		
		for (int i = 1; i <= n; i++) {
			if (i&1) {
				a[i] = 2*i - 1;
				a[i + n] = 2*i;
			} else {
				a[i] = 2*i;
				a[i + n] = 2*i - 1;
			}
		}
		
		for (int i = 1; i <= n*2; i++) {
			printf("%d ", a[i]);
		}
		
		puts("");
	}
}