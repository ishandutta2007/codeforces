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
const int N = (1 << 18) + 5, MOD = 998244353;

std::mt19937 rng(std::random_device {}());
int P = rng() % MOD;

char s[N];

int n, pw[N];
std::vector <int> h[N << 2];
void Build(int o, int l, int r) {
	if(r - l == 1) {
		h[o].push_back(s[l] - 'a');
		return;
	}
	h[o].resize(r - l);
	int mid = (l + r) >> 1, d = r - l, b = 30 - __builtin_clz(d);
	Build(o << 1, l, mid);
	Build(o << 1 | 1, mid, r);
	for(int i = 0; i < d; ++i) {
		if((i >> b) & 1) {
			h[o][i] = (
				h[o << 1 | 1][i ^ (1 << b)] +
				1LL * pw[d >> 1] * h[o << 1][i ^ (1 << b)]
			) % MOD;
		} else {
			h[o][i] = (
				h[o << 1][i] + 1LL * pw[d >> 1] * h[o << 1 | 1][i]
			) % MOD;
		}
	}
}

int FindLcp(int x, int y, int d, int j, int k) {
	if(d == 1) return h[x][0] == h[y][0];
	int _x = x << 1 | (j / (d >> 1)),
		_y = y << 1 | (k / (d >> 1));
	j &= ~(d >> 1); k &= ~(d >> 1);
	if(h[_x][j] == h[_y][k])
		return FindLcp(_x ^ 1, _y ^ 1, d >> 1, j, k) + (d >> 1);
	else return FindLcp(_x, _y, d >> 1, j, k);
}

bool Check(int j, int k) {
	int lcp = FindLcp(1, 1, 1 << n, j, k);
	return s[lcp ^ j] < s[lcp ^ k];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		scanf("%s", s);
		pw[0] = 1;
		for(int i = 1; i < 1 << n; ++i)
			pw[i] = 1LL * pw[i - 1] * P % MOD;
		Build(1, 0, 1 << n);
		int j = 0;
		for(int i = 0; i < 1 << n; ++i)
			if(Check(i, j)) j = i;
		for(int i = 0; i < 1 << n; ++i)
			printf("%c", s[i ^ j]);
		printf("\n");
	} return 0;
}