#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, a[1 << N], r1[1 << N], r2[1 << N];

inline void update(int x, int p) {
	if(p >= r1[x]) r2[x] = r1[x], r1[x] = p;
	else if(p >= r2[x]) r2[x] = p;
} 

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), update(a[i], i);
	for(int i = 0; i < N; ++i)
		for(int s = 0; s < 1 << N; ++s)
			if(!(s >> i & 1)) {
				update(s, r2[s ^ (1 << i)]);
				update(s, r1[s ^ (1 << i)]);
			}
	int ans = 0;
	for(int i = 1; i <= n - 2; ++i) {
		int cur = 0;
		for(int k = 19; ~k; --k) {
			if(a[i] >> k & 1) continue;
			if(r2[cur | (1 << k)] <= i) continue;
			cur |= (1 << k);
		}
		ans = max(ans, a[i] | cur);
	}
	printf("%d", ans);
}