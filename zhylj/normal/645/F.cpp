#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e6 + 5, MOD = 1e9 + 7;

int QPow(int a, int b) {
	int ret = 1, bas = a;
	for(; b; b >>= 1, bas = 1LL * bas * bas % MOD)
		if(b & 1) ret = 1LL * ret * bas % MOD;
	return ret;
}
int Inv(int a) { return QPow(a, MOD - 2); }

int fac[N], fac_inv[N], p[N], phi[N], p_cnt;
bool flag[N];
void Init() {
	phi[1] = 1;
	for(int i = 2; i < N; ++i) {
		if(!flag[i]) {
			p[++p_cnt] = i;
			phi[i] = i - 1;
		}
		for(int j = 1; j <= p_cnt && i * p[j] < N; ++j) {
			flag[i * p[j]] = true;
			if(i % p[j] == 0) { phi[i * p[j]] = phi[i] * p[j]; break; }
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
	fac[0] = 1;
	for(int i = 1; i < N; ++i)
		fac[i] = 1LL * fac[i - 1] * i % MOD;
	fac_inv[N - 1] = Inv(fac[N - 1]);
	for(int i = N - 2; ~i; --i)
		fac_inv[i] = 1LL * fac_inv[i + 1] * (i + 1) % MOD;
}
int C(int x, int y) {
	if(x < y || y < 0) return 0;
	return 1LL * fac[x] * fac_inv[y] % MOD * fac_inv[x - y] % MOD;
}

int k, ans, cnt[N];
void ModifyCnt(int g, int v) {
	ans = (ans - 1LL * C(cnt[g], k) * phi[g]) % MOD;
	cnt[g] += v;
	ans = (ans + 1LL * C(cnt[g], k) * phi[g]) % MOD;
}
void Insert(int x) {
	for(int i = 1; i * i <= x; ++i) {
		if(x % i == 0) {
			ModifyCnt(i, 1);
			if(i * i != x) ModifyCnt(x / i, 1);
		}
	}
	ans = (ans + MOD) % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	Init();
	while(test_case_cnt--) {
		int n, q; rd(n, k, q);
		for(int i = 1; i <= n; ++i) {
			int x; rd(x);
			Insert(x);
		}
		for(int i = 1; i <= q; ++i) {
			int x; rd(x);
			Insert(x);
			printf("%d\n", ans);
		}
	} return 0;
}