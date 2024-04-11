#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int T, n, a[N], mx, mn;

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d", &n);
		mx = mn = 1;
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			
			if (a[mx] < a[i]) {
				mx = i;
			}
			
			if (a[mn] > a[i]) {
				mn = i;
			}
		}
		
		printf("%d %d\n", mx, mn);
	}
}