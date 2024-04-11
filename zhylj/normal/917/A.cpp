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
const int kN = 5e3 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

char str[kN];

int main() {
	int T = 1; //rd(T);
	while(T--) {
		int ans = 0, n;
		scanf("%s", str + 1);
		n = strlen(str + 1);
		for(int i = 1; i <= n; ++i) {
			int l = 0, r = 0;
			for(int j = i; j <= n; ++j) {
				if(str[j] == '(') ++l, ++r;
				if(str[j] == ')') --l, --r;
				if(str[j] == '?') --l, ++r;
				if(l < 0) l = 1;
				if(r < l) break;
				if(l == 0) {
					++ans;
				}
			//	printf("%d %d %d %d\n", i, j, l, r);
			}
		}
		printf("%d\n", ans);
	} return 0;
}