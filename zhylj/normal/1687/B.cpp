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
const int N = 500 + 5;

int n, m;

char s[N];
int Ask(std::vector <int> x) {
	memset(s, 0, sizeof(s));
	for(int i = 1; i <= m; ++i) s[i] = '0';
	for(int v : x) s[v] = '1';
	printf("? %s\n", s + 1);
	fflush(stdout);
	int ret; rd(ret);
	return ret;
}

int idx[N], w[N];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("a.in", "r", stdin);
	//freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 1; i <= m; ++i) {
			idx[i] = i;
			w[i] = Ask((std::vector <int>) { i });
		}
		std::sort(idx + 1, idx + m + 1, [&](const int &x, const int &y) {
			return w[x] < w[y];
		});
		int ans = w[idx[1]];
		std::vector <int> cur;
		cur.push_back(idx[1]);
		for(int i = 2; i <= m; ++i) {
			cur.push_back(idx[i]);
			if(Ask(cur) != ans + w[idx[i]]) {
				cur.pop_back();
			} else ans += w[idx[i]];
		}
		printf("! %d\n", ans);
		fflush(stdout);
	} return 0;
}