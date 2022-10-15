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

ll a, b, n, ans_i = 0, ans = -kInfLL;
ll Sq(ll x) { return x * x; }
int main() { 
	int T = 1; //rd(T);
	while(T--) {
		rd(a, b);
		if((!a) || b <= 1) {
			printf("%lld\n", a * a - b * b);
			for(int i = 1; i <= a; ++i) printf("o");
			for(int i = 1; i <= b; ++i) printf("x");
			return 0;
		}
		for(int i = 1; i <= std::min(a, b - 1); ++i) {
			ll per = b / (i + 1), res = b % (i + 1);
			//printf("%d %d %d %lld %lld\n", i, per, res, (i - 1) + Sq(a - (i - 1)), res * Sq(per + 1) + (i + 1 - res) * Sq(per));
			ll tmp_ans = (i - 1) + Sq(a - (i - 1)) - res * Sq(per + 1) - (i + 1 - res) * Sq(per);
			if(!ans_i || tmp_ans > ans) ans_i = i, ans = tmp_ans;
		}
	//	printf("%d\n", ans_i);
		printf("%lld\n", ans);
		for(int i = 1; i <= ans_i + 1; ++i) {
			ll per = b / (ans_i + 1), res = b % (ans_i + 1);
			for(int j = 1; j <= per + (i <= res); ++j) printf("x");
			if(i == 1) {
				//printf("%d\n", a - (ans_i - 1));
				for(int j = 1; j <= a - (ans_i - 1); ++j) printf("o");
			} else if(i != ans_i + 1)
				printf("o");
		}
	} return 0;
}