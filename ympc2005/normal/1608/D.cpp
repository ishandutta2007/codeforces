#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 10, mod = 998244353;
 
int n, fac[N], inv[N], ans, B, W, D, m;
 
bool ok;
 
string s[N];
 
int fpow_(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = 1ll*a*a%mod) {
		if (b&1) {
			res = 1ll*res*a%mod;
		}
	}
 
	return res;
}
 
int C_(int n, int k) {
	return n < k ? 0 : 1ll*fac[n]*inv[k]%mod*inv[n - k]%mod;
}
 
bool check_(string t) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (s[i][j] != '?' && s[i][j] != t[j]) {
				return 0;
			}
		}
	}
 
	return 1;
}
 
int main() {
	scanf("%d", &n), fac[0] = 1;
 
	for (int i = 1; i <= n*2; i++) {
		fac[i] = 1ll*fac[i - 1]*i%mod;
	}
 
	inv[n*2] = fpow_(fac[n*2], mod - 2);
 
	for (int i = n*2; i; i--) {
		inv[i - 1] = 1ll*inv[i]*i%mod;
	}
 
	for (int i = 1; i <= n; i++) {
		cin>>s[i];
 
		for (int j = 0; j < 2; j++) {
			B += s[i][j] == 'B';
			W += s[i][j] == 'W';
		}
 
		if (s[i] == "BB") {
			D++;
			ok = 1;
		}
 
		if (s[i] == "WW") {
			D--;
			ok = 1;
		}
 
		if (s[i] == "??") {
			m++;
		}
	}
 
	if (B > n || W > n) {
		puts("0");
		exit(0);
	}
 
	ans = C_(n*2 - B - W, n - B);
 
	if (!ok) {
		ans = (ans - fpow_(2, m))%mod;
	}
 
	if (check_("BW")) {
		ans++;
	}

	if (check_("WB")) {
		ans++;
	}
 
	printf("%d\n", (ans%mod + mod)%mod);
}