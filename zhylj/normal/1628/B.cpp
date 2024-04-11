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
const int N = 1e5 + 5;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		int n; rd(n);
		std::set <std::string> S, S_2;
		bool flag = false;
		for(int i = 1; i <= n; ++i) {
			std::string str, tmp; std::cin >> str;
			if(str.front() == str.back()) { flag = true; break; }
			else {
				tmp = str;
				std::reverse(tmp.begin(), tmp.end());
				if(S.count(tmp) || S_2.count(tmp)) { flag = true; break; }
				if(str.size() == 3) {
					tmp = str;
					std::reverse(tmp.begin(), tmp.end());
					tmp.pop_back();
					if(S.count(tmp)) { flag = true; break; }
				}
			}
			S.insert(str);
			if(str.size() == 3) {
				str.pop_back();
				S_2.insert(str);
			}
		}
		printf(flag ? "YES\n" : "NO\n");
	} return 0;
}