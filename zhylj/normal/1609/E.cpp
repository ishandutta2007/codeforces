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
#define mn(o, x, y) seg[o].mn[x][y]
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1e5 + 5, INF = 0x3f3f3f3f;

int n, q;
char str[N];

struct Node {
	int mn[3][3];
} seg[N << 3];
void Update(int o) {
	memset(seg[o].mn, 0x3f, sizeof(seg[o].mn));
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 3; ++k)
				mn(o, i, j) = std::min(mn(o, i, j), mn(o << 1, i, k) + mn(o << 1 | 1, k, j));
}
char t[4] = "abc";
void GetVal(int o, char c) {
	memset(seg[o].mn, 0x3f, sizeof(seg[o]));
	for(int i = 0; i < 3; ++i) {
		mn(o, i, i) = (c == t[i]);
		if(i < 2) mn(o, i, i + 1) = (c != t[i]);
	}
}
void Modify(int o, int l, int r, int p, char c) {
	if(l == r) GetVal(o, c);
	else {
		int mid = (l + r) >> 1;
		if(p <= mid) Modify(o << 1, l, mid, p, c);
		else Modify(o << 1 | 1, mid + 1, r, p, c);
		Update(o);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		scanf("%s", str + 1);
		for(int i = 1; i <= n; ++i)
			Modify(1, 1, n, i, str[i]);
		while(q--) {
			int pos; rd(pos);
			char s[10]; scanf("%s", s);
			Modify(1, 1, n, pos, s[0]);
			int ans = n;
			for(int i = 0; i < 3; ++i)
				ans = std::min(ans, mn(1, 0, i));
			printf("%d\n", ans);
		}
	} return 0;
}