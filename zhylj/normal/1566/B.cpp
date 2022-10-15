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
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;

int n;
char str[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; rd(test_case_cnt);
    while(test_case_cnt--) {
        scanf("%s", str + 1);
		n = strlen(str + 1);
		int cnt_0 = 0;
		for(int i = 1; i <= n; ++i)
			if(str[i] == '0' && str[i - 1] != '0')
				++cnt_0;
		if(cnt_0 == 0) printf("0\n");
		else if(cnt_0 == 1) printf("1\n");
		else printf("2\n");
    } return 0;
}