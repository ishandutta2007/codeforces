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
const int kN = 5e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int Query(int x) {
	printf("? %d\n", x);
	fflush(stdout);
	rd(x);
	return x;
}

int n;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		int l = 1, r = n;
		while(r - l > 1) {
			int mid = (l + r) >> 1, a0, a1, a2;
			a0 = Query(mid - 1), a1 = Query(mid), a2 = Query(mid + 1);
			if(a1 < a0 && a1 < a2) {
				printf("! %d\n", mid);
				return 0;
			} else if(a0 < a1) r = mid - 1;
			else l = mid + 1;
		}
		if(r - l == 1) {
			int xl = Query(l), xr = Query(r);
			if(xl < xr) printf("! %d\n", l);
			else printf("! %d\n", r);
		} else {
			printf("! %d\n", l);
		}
	} return 0;
}