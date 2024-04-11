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
const int N = 5e5 + 5;

int n, k, s[N], a[N], pre_mn[N][2], pre_mx[N][2], suf_mn[N][2], suf_mx[N][2];
char str[N];

int Query(int l, int r, int x) {
	if(l > r) return 0;
	int cnt = s[r] - s[l - 1];
	if(!x) cnt = r - l + 1 - cnt;
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		scanf("%s", str + 1);
		for(int i = 1; i <= n; ++i) {
			a[i] = str[i] - '0';
			s[i] = s[i - 1] + a[i];
		}
		for(int i = 0; i <= n + 1; ++i) 
			for(int d = 0; d < 2; ++d)
				pre_mn[i][d] = suf_mn[i][d] = n + 1;
		for(int i = 1; i <= n + 1; ++i)
			for(int d = 0; d < 2; ++d) {
				pre_mn[i][d] = pre_mn[i - 1][d];
				pre_mx[i][d] = pre_mx[i - 1][d];
				if(d == a[i]) {
					pre_mn[i][d] = std::min(pre_mn[i][d], i);
					pre_mx[i][d] = std::max(pre_mx[i][d], i);
				}
			}
		for(int i = n; ~i; --i)
			for(int d = 0; d < 2; ++d) {
				suf_mn[i][d] = suf_mn[i + 1][d];
				suf_mx[i][d] = suf_mx[i + 1][d];
				if(d == a[i]) {
					suf_mn[i][d] = std::min(suf_mn[i][d], i);
					suf_mx[i][d] = std::max(suf_mx[i][d], i);
				}
			}
		bool flag = true;
		for(int i = 1; i + k - 1 <= n; ++i)
			for(int d = 0; d < 2; ++d) {
				if(Query(1, i - 1, d) + Query(i + k, n, d) + k == n) {
					printf("tokitsukaze\n");
					return 0;
				}
				if(std::max(suf_mx[i + k][d], pre_mx[i - 1][d]) -
					std::min(pre_mn[i - 1][d], suf_mn[i + k][d]) >= k) flag = false;
			}
		if(!flag) printf("once again\n");
		else printf("quailty\n");
	} return 0;
}