#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 6e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

struct Bit {
	ll T[N + 5];
	void Modify(int o, int v) {
		for(; o < N; o += o & -o)
			T[o] += v;
	}
	ll Query(int o) {
		ll ret = 0;
		for(; o; o -= o & -o) ret += T[o];
		return ret;
	}
	ll Query(int l, int r) {
		return Query(std::min(r, N - 1)) - Query(std::max(l - 1, 0));
	}
} S, C, Ct;
int n; ll p[N], A[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(A[i]);
			ll t = 0;
			p[i] = p[i - 1] + 1LL * (i - 1) * A[i] + Ct.Query(A[i]);
			for(int j = 0; j * A[i] < N; ++j) {
				int l = j * A[i], r = (j + 1) * A[i] - 1;
				t += S.Query(l, r) - j * A[i] * C.Query(l, r);
				if(j) Ct.Modify(l, -A[i]);
			}
			p[i] = p[i] + t;
			S.Modify(A[i], A[i]);
			C.Modify(A[i], 1);
		}
		for(int i = 1; i <= n; ++i)
			printf("%lld ", p[i]);
		printf("\n");
	} return 0;
}