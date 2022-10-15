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
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

struct Factor {
	int val;
	std::vector <int> pf;
} d[kN];
int n, p[kN], p_cnt, cnt, d_cnt, tn;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		for(int i = 1; i <= d_cnt; ++i) d[i].pf.clear();
		cnt = p_cnt = d_cnt = 0;
		rd(n); tn = n;
		for(int i = 2; i * i <= n; ++i) 
			if(n % i == 0) {
				d[++d_cnt].val = i;
				if(i * i != n) d[++d_cnt].val = n / i;
			}
		d[++d_cnt].val = n;
		for(int i = 2; i * i <= tn; ++i) {
			if(tn % i == 0) p[++p_cnt] = i;
			while(tn % i == 0) tn /= i;
		}
		if(tn != 1) p[++p_cnt] = tn;
		if(p_cnt == 2 && p[1] * p[2] == n) {
			printf("%d %d %d\n1\n", p[1], p[2], n);
			continue;
		} else if(p_cnt == 1) {
			for(int i = 1; i <= d_cnt; ++i) printf("%d ", d[i].val);
			printf("\n0\n");
			continue;
		}
		--d_cnt;
		for(int i = 1; i <= d_cnt; ++i) {
			for(int j = 1; j <= p_cnt; ++j)
				if(d[i].val % p[j] == 0) d[i].pf.push_back(p[j]);
		}
		std::sort(d + 1, d + d_cnt + 1, [](const Factor &x, const Factor &y) {
			int fx = x.pf.front(), fy = y.pf.front(), siz_x = x.pf.size(), siz_y = y.pf.size();
			if(fx != fy) return fx < fy;
			else if(siz_x == 1 || siz_y == 1) return siz_x < siz_y;
			else return siz_x != siz_y ? siz_x > siz_y : x.pf[1] > y.pf[1];
		});
		/*for(int i = 1; i <= d_cnt; ++i) {
			printf("%d: ", d[i].val);
			for(auto j : d[i].pf) printf("%d ", j);
			printf("\n");
		}*/
		for(int i = 1; i <= d_cnt; ++i) {
			printf("%d ", d[i].val);
		}
		printf("%d \n0\n", n);
	} return 0;
}