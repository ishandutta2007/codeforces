#include <bits/stdc++.h>

#pragma GCC target("popcnt")

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
const int N = 2e5 + 5, Q = 4e5 + 5, S = 64;

int n, m, ans[Q];
std::bitset <N> a, b;

struct Ask {
	int p, q, len, idx;
}; std::vector <Ask> A[S];
ull b_per[N / S], a_per[N / S];
int cnt[N / S + 5][N / S + 5];
void Init(int mov) {
	memset(a_per, 0, sizeof(a_per));
	memset(cnt, 0, sizeof(cnt));
	for(int i = mov; i - mov < n; ++i)
		a_per[i / S] |= (ull)a[i - mov] << (i % S);
	for(int i = 0; i <= (n + mov) / S; ++i) {
		for(int j = 0; j <= m / S; ++j) {
			cnt[i][j] += __builtin_popcountll(a_per[i] ^ b_per[j]);
			cnt[i + 1][j + 1] = cnt[i][j];
		}
	}
}
int Query(int p, int q, int len) {
	int ret = 0, d = q - p, l = q, r = q + len - 1;
	if(l / S == r / S) {
		for(int i = l; i <= r; ++i)
			ret += a[i - d] ^ b[i];
	} else {
		for(int i = l; i / S == l / S; ++i)
			ret += a[i - d] ^ b[i];
		for(int i = r; i / S == r / S; --i)
			ret += a[i - d] ^ b[i];
		int mov = (d % S + S) % S,
			mov_i = (p + mov) / S - l / S;
		ret += cnt[r / S - 1 + mov_i][r / S - 1];
		ret -= cnt[l / S + mov_i][l / S];
	}
	return ret;
}

char s[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s%s", s, t);
		n = strlen(s); m = strlen(t);
		for(int i = 0; i < n; ++i) a[i] = s[i] - '0';
		for(int i = 0; i < m; ++i) b[i] = t[i] - '0';
		for(int i = 0; i < m; ++i)
			b_per[i / S] |= (ull)b[i] << (i % S);
		int r; rd(r);
		for(int i = 0; i < r; ++i) {
			int p, q, len; rd(p, q, len);
			A[((q - p) % S + S) % S].push_back((Ask) { p, q, len, i });
		}
		for(int i = 0; i < S; ++i) {
			Init(i);
			for(Ask j : A[i])
				ans[j.idx] = Query(j.p, j.q, j.len);
		}
		for(int i = 0; i < r; ++i)
			printf("%d\n", ans[i]);
	} return 0;
}