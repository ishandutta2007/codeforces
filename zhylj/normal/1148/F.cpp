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
const int N = 3e5 + 5, B = 62;

ll sum, mk[N], chs_mk[B];
int n, val[N];
std::bitset <N> a[B], suf[B];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) {
			rd(val[i], mk[i]);
			sum += val[i];
		}
		if(sum < 0) {
			for(int i = 1; i <= n; ++i)
				val[i] = -val[i];
		}
		for(int i = 0; i < B; ++i) {
			for(int j = 1; j <= n; ++j)
				if((mk[j] >> i) & 1) a[i][j] = 1;
			chs_mk[i] = 1LL << i;
		}
		for(int i = 0; i < B; ++i) {
			int f = a[i]._Find_first();
			for(int j = i + 1; j < B; ++j) {
				int n_f = a[j]._Find_first();
				if(n_f < f) {
					std::swap(a[i], a[j]);
					std::swap(chs_mk[i], chs_mk[j]);
					f = n_f;
				}
			}
			if(f >= N) break;
			for(int j = 0; j < B; ++j)
				if(j != i && a[j][f]) {
					a[j] ^= a[i];
					chs_mk[j] ^= chs_mk[i];
				}
			suf[i] = a[i];
		}
		for(int i = B - 2; ~i; --i)
			suf[i] |= suf[i + 1];
		ll s = 0;
		for(int i = 0; i < B; ++i) {
			int f = a[i]._Find_first(), nxt_f = i != B - 1 ? a[i + 1]._Find_first() : N;
			ll cur_sum = 0;
			for(int j = f; j < N; j = a[i]._Find_next(j))
				if(i == B - 1 || !suf[i + 1][j]) cur_sum += val[j];
			if(cur_sum > 0) {
				s ^= chs_mk[i];
				for(int j = f; j < N; j = a[i]._Find_next(j))
					val[j] = -val[j];
			}
		}
		printf("%lld\n", s);
	} return 0;
}