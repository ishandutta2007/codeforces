#include <bits/stdc++.h>
using namespace std;

const int n = 20;
int m, a, f[1 << n], po[1 << n];

const int mod = 1e9 + 7;
inline int add(int x, int y) {
	x += y;
	if(x >= mod) x -= mod;
	return x;
}
inline int sub(int x, int y) {
	x -= y;
	if(x < 0) x += mod;
	return x;
}
inline int mul(int x, int y) {
	return 1ll * x * y % mod;
}                                    

int main() {
	scanf("%d", &m);
	po[0] = 1; for(int i = 1; i <= m; ++i) po[i] = mul(po[i - 1], 2);
	while(m--) scanf("%d", &a), ++f[a];
	for(int i = 0; i < n; ++i)
		for(int s = 0; s < 1 << n; ++s)
			if(!(s >> i & 1)) f[s] += f[s ^ (1 << i)];
	int ans = 0;
	for(int s = 0; s < 1 << n; ++s) {
		if(__builtin_parity(s)) ans = sub(ans, po[f[s]]);
		else ans = add(ans, po[f[s]]);
	}
	printf("%d", ans);
}