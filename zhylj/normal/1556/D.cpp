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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n, k, a[N], b[N], c[N], d[N];
int Or(int x, int y) {
	printf("or %d %d\n", x, y);
	fflush(stdout);
	int ret; rd(ret);
	return ret;
}
int And(int x, int y) {
	printf("and %d %d\n", x, y);
	fflush(stdout);
	int ret; rd(ret);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, k);
		for(int i = 2; i <= n; ++i) b[i] = Or(1, i);
		for(int i = 2; i <= n; ++i) c[i] = And(1, i);
		int tmp_or = Or(2, 3),
			tot_and = 0, tot_or = (1 << 30) - 1;
		for(int i = 2; i <= n; ++i) tot_and |= c[i], tot_or &= b[i];
		for(int i = 0; i < 31; ++i) {
			if(((tot_or >> i) & 1) == 1) a[1] |= 1 << i;
			if(((tot_and >> i) & 1) == 0) a[1] &= ~(1 << i);
			if(((tot_and >> i) & 1) == 0 && ((tot_or >> i) & 1) == 1) {
				if(((tmp_or >> i) & 1) == 0) a[1] |= 1 << i;
			}
			if(((a[1] >> i) & 1) == 1) {
				for(int j = 2; j <= n; ++j) a[j] |= c[j] & (1 << i);
			} else for(int j = 2; j <= n; ++j) a[j] |= b[j] & (1 << i);
		}
		std::sort(a + 1, a + n + 1);
		printf("finish %d\n", a[k]);
	} return 0;
}