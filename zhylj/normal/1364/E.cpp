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

int n, p[kN];

int Query(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int ret; rd(ret);
	return ret;
}
int RandDiff(int x) {
	int y = rand() % n + 1;
	while(x == y) y = rand() % n + 1;
	return y;
}
int GetVal(int x) {
	int cur = Query(x, RandDiff(x));
	for(int i = 1; i <= 15; ++i) {
		int tmp = RandDiff(x), tmp2 = Query(x, tmp);
		cur &= tmp2;
	}
	return cur;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		srand(time(0));
		rd(n);
		int x = rand() % n + 1, cur_x = GetVal(x);
		for(int i = 1; i <= n; ++i) if(x != i) {
			if(Query(x, i) == cur_x) {
				cur_x = GetVal(i);
				x = i;
			}
		}
		p[x] = cur_x;
		for(int i = 1; i <= n; ++i) if(i != x) {
			p[i] = Query(x, i);
		}
		printf("! ");
		for(int i = 1; i <= n; ++i)
			printf("%d ", p[i]);
		printf("\n");
	} return 0;
}