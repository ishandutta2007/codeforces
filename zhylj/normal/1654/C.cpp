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
const int N = 6e6 + 5;

std::map <ll, int> buk;
int n, bg, ed; ll a[N], st[N];
bool flag;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		buk.clear();
		rd(n); flag = true;
		ll s = 0;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(!buk.count(a[i])) buk[a[i]] = 0;
			++buk[a[i]];
			s += a[i];
		}
		st[bg = ed = 1] = s;
		for(int i = 1; i <= n * 30 && bg <= ed; ++i) {
			if(!buk.count(st[bg]) || !buk[st[bg]]) {
				st[++ed] = st[bg] / 2;
				st[++ed] = (st[bg] + 1) / 2;
				++bg;
			} else --buk[st[bg++]];
		}
		for(auto p : buk)
			if(p.se != 0) flag = false;
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}