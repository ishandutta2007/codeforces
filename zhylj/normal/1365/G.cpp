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

ll Query(std::vector <int> a) {
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
	if(!a.size()) return 0;
	printf("? %d ", a.size());
	for(auto i : a) printf("%d ", i);
	printf("\n");
	fflush(stdout);
	ll ret; rd(ret);
	return ret;
}

int n, m[kN]; ll s[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(n);
		for(int i = 1, j = 0; i <= n; ++i) {
			for(; __builtin_popcount(j) != 6; ++j);
			m[i] = j++;
		}
		for(int j = 0; j < 13; ++j) {
			std::vector <int> a;
			for(int i = 1; i <= n; ++i) if((m[i] >> j) & 1)
				a.push_back(i);
			s[j] = Query(a);
		}
		printf("! ");
		for(int i = 1; i <= n; ++i) {
			ll ans = 0;
			for(int j = 0; j < 13; ++j) if(~(m[i] >> j) & 1) {
				ans |= s[j];
			}
			printf("%lld ", ans);
		}
		printf("\n");
	} return 0;
}