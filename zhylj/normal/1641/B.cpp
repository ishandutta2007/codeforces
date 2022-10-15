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

int n, a[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		std::vector <pii> opt;
		std::vector <int> div;
		std::map <int, int> cnt;
		for(int i = 1; i <= n; ++i) {
			rd(a[i]);
			if(!cnt.count(a[i])) cnt[a[i]] = 0;
			cnt[a[i]] ^= 1;
		}
		bool flag = true;
		for(auto p : cnt)
			if(p.se) flag = false;
		if(!flag) {
			printf("-1\n");
			continue;
		}
		int tot = n;
		for(int mov = 0; tot; ) {
			int j;
			for(j = 2; j <= tot; ++j)
				if(a[j] == a[1]) break;
			for(int i = 2; i < j; ++i) {
				opt.push_back(mkp(mov + i + j - 2, a[i]));
			}
			std::reverse(a + 1, a + j + 1);
			mov += 2 * (j - 1);
			div.push_back(2 * (j - 1));
			for(int i = j + 1; i <= tot; ++i)
				a[i - 1] = a[i];
			tot -= 1;
			for(int i = 2; i <= tot; ++i)
				a[i - 1] = a[i];
			tot -= 1;
		}
		printf("%d\n", (int)opt.size());
		for(auto i : opt) printf("%d %d\n", i.fi, i.se);
		printf("%d\n", (int)div.size());
		for(auto i : div) printf("%d ", i);
		printf("\n");
	} return 0;
}