#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, mod = 998244353;

int T, n, fac[N], inv[N], m, tot; 

char s[N];

int fpow_(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = 1ll*a*a%mod) {
		if (b&1) {
			res = 1ll*res*a%mod;
		}
	}
	
	return res;
}

int calc_(int n, int k) {
	return n < k ? 0 : 1ll*fac[n]*inv[k]%mod*inv[n - k]%mod;
}

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%d%s", &n, s + 1);
		
		m = tot = 0;
		
		for (int i = 1; i <= n; i++) {
			if (s[i] == '1' && s[i + 1] == '1') {
				m++;
				i++;
			} else if (s[i] == '1') {
				tot++;
			}
		}
		
		fac[0] = 1;
		
		for (int i = 1; i <= n; i++) {
			fac[i] = 1ll*fac[i - 1]*i%mod; 
		}
		
		inv[n] = fpow_(fac[n], mod - 2);
		
		for (int i = n; i; i--) {
			inv[i - 1] = 1ll*inv[i]*i%mod;
		}
		
		printf("%d\n", (calc_(m + (n - 2*m + 1 - tot) - 1, (n - 2*m + 1 - tot) - 1)%mod + mod)%mod);
	}
}