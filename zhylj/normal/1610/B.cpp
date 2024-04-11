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

bool Check(int x) {
	std::vector <int> b, tmp_b;
	for(int i = 1; i <= n; ++i)
		if(a[i] != x) {
			b.push_back(a[i]);
			tmp_b.push_back(a[i]);
		}
	std::reverse(tmp_b.begin(), tmp_b.end());
	for(int i = 0; i < b.size(); ++i)
		if(b[i] != tmp_b[i]) return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]);
		bool flag = true;
		for(int i = 1; i <= n / 2; ++i) {
			if(a[i] != a[n - i + 1]) {
				if(!Check(a[i]) && !Check(a[n - i + 1]))
					flag = false;
				break;
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}