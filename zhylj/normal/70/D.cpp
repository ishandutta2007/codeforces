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
typedef std::pair <int, ll> pii;
typedef std::pair <ff, pii> pfi;
const int N = 5e5 + 5;
const ll Inf = 4e12;

struct Convex {
	std::set <pii> S;
	Convex() {
		S.insert(mkp(-1e6 - 1, -Inf));
		S.insert(mkp(1e6 + 1, -Inf));
	}
	bool Check(int x, int y) {
		auto it = S.lower_bound(mkp(x, y));
		pii R = *it, L = *(--it);
		return (R.fi - x) * (L.se - y) >= (L.fi - x) * (R.se - y);
	}
	void Insert(int x, int y) {
		if(Check(x, y)) return;
		auto it_L = S.lower_bound(mkp(x, y)), it_R = it_L; --it_L;
		std::vector <pii> tmp;
		for(auto it_cur = it_L--; it_cur != S.begin(); --it_cur, --it_L) {
			pii u = *it_L, v = *it_cur;
			if((x - u.fi) * (v.se - u.se) <= (v.fi - u.fi) * (y - u.se))
				tmp.push_back(v);
			else break;
		}
		for(auto it_cur = it_R++; it_R != S.end(); ++it_cur, ++it_R) {
			pii u = *it_R, v = *it_cur;
			if((x - u.fi) * (v.se - u.se) >= (v.fi - u.fi) * (y - u.se))
				tmp.push_back(v);
			else break;
		}
		for(auto i : tmp) S.erase(i);
		S.insert(mkp(x, y));
	}
} U, D;

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		int q; rd(q);
		for(int i = 1; i <= q; ++i) {
			int opt, x, y; rd(opt, x, y);
			if(opt == 1) {
				U.Insert(x, y);
				D.Insert(x, -y);
			} else {
				printf(U.Check(x, y) && D.Check(x, -y) ? "YES\n" : "NO\n");
			}
		}
	} return 0;
}