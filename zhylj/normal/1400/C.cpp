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

int n, x, w[kN]; char s[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; rd(T);
	while(T--) {
		bool flag = true;
		scanf("%s%d", s + 1, &x);
		n = strlen(s + 1);
		for(int i = 1; i <= n; ++i) w[i] = 1;
		for(int i = 1; i <= n; ++i)
			if(s[i] == '0') {
				//printf("%d %d\n", i + x, i - x);
				if(i + x <= n || i - x > 0) {
					if(i + x <= n) w[i + x] = 0;
					if(i - x > 0) w[i - x] = 0;
				}
			}
	//	printf("%d\n", (int)flag);
	//	for(int i = 1; i <= n; ++i) printf("%d", w[i]);
	//	printf("\n");
		for(int i = 1; i <= n; ++i) {
			if(s[i] == '1') {
				bool tmp_flag = false;
				if(i + x <= n && w[i + x]) tmp_flag = true;
				if(i - x > 0 && w[i - x]) tmp_flag = true;
				if(!tmp_flag) flag = false;
			}
		}
		if(flag) {
			for(int i = 1; i <= n; ++i) printf("%d", w[i]);
			printf("\n");
		} else printf("-1\n");
	} return 0;
}