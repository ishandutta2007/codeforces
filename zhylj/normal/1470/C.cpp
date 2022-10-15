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

int n, k, col[kN], p[kN], cnt = 0;

int Query(int x) {
	x = (x - 1) % n + 1;
	if(x <= 0) x += n;
	printf("? %d\n", x);
	fflush(stdout);
	int ret; rd(ret);
	return ret;
}

int c[kN];
void GetAns(int l, int r) {
	for(int i = l - 1; i <= r + 1; ++i) {
		c[i] = Query(i);
	}
	for(int i = l; i <= r; ++i) {
		if(c[i - 1] >= c[i] && c[i + 1] > c[i]) {
			printf("! %d\n", i % n + 1);
			return;
		}
	}
}

int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		srand(time(0));
		rd(n, k);// Init();
		for(int i = 1; i <= 340; ++i) Query(1);
		int bg = rand() % n + 1;
		for(int i = bg; i < bg + n - 1; i += 340) {
			p[++cnt] = i; col[cnt] = Query(i);
		}
		p[++cnt] = bg + n; col[cnt] = col[1];
		for(int i = 1; i < cnt; ++i) {
			if(col[i] < col[i + 1]) {
				GetAns(p[i], p[i + 1]);
				return 0;
			}
		}
		GetAns(1, n);
	} return 0;
}