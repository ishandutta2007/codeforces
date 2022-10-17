#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
inline void add(int &a, int b) { (a += b) >= mod && (a -= mod); }
inline int Add(int a, int b) { return add(a, b), a; }
inline void sub(int &a, int b) { (a -= b) < 0 && (a += mod); }
inline int Sub(int a, int b) { return sub(a, b), a; }
inline void mul(int &a, int b) { a = 1ll * a * b % mod; }
inline int Mul(int a, int b) { return 1ll * a * b % mod; }
const int N = 1000005;
int inv[N], fac[N], fac_inv[N];
int tot, pr[N], mn[N], phi[N];
int n, k, q, x, cnt[N], ans;
vector<int> d[N];
inline void prework(int n) {
    for(int i = 0; i <= 1; ++i) inv[i] = fac[i] = fac_inv[i] = 1;
    for(int i = 2; i <= n; ++i) fac[i] = Mul(i, fac[i - 1]);
    for(int i = 2; i <= n; ++i) inv[i] = Mul(inv[mod % i], mod - mod / i);
    for(int i = 2; i <= n; ++i) fac_inv[i] = Mul(inv[i], fac_inv[i - 1]);
}
inline void sieve(int n) {
	phi[1] = 1;
	for(int i = 2; i <= n; ++i) {
		if(!mn[i]) pr[++tot] = i, mn[i] = i, phi[i] = i - 1;
		for(int j = 1; j <= tot && i * pr[j] <= n; ++j) {
			mn[i * pr[j]] = pr[j];
			if(i % pr[j] == 0) {
				phi[i * pr[j]] = phi[i] * pr[j];
				break;
			} 
			phi[i * pr[j]] = phi[i] * (pr[j] - 1); 
		}
	}
	for(int i = 1; i <= n; ++i) 
		for(int j = i; j <= n; j += i)
			d[j].push_back(i);
}
inline int C(int n, int m) {
	if(n < m) return 0;
	return Mul(fac[n], Mul(fac_inv[m], fac_inv[n - m]));
}

inline void update(int x) {
	for(int i = 0; i < d[x].size(); ++i) {
		int y = d[x][i]; ++cnt[y]; 
		add(ans, Mul(phi[y], Sub(C(cnt[y], k), C(cnt[y] - 1, k))));
	}
}

int main() {
	prework(2e5), sieve(1e6);
	scanf("%d%d%d", &n, &k, &q);
	while(n--) scanf("%d", &x), update(x);
	while(q--) scanf("%d", &x), update(x), printf("%d\n", ans);
	return 0;
}