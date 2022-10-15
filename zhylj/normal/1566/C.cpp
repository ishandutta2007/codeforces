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

int n, c[N];
char s[N], t[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; rd(test_case_cnt);
    while(test_case_cnt--) {
        rd(n);
        scanf("%s%s", s + 1, t + 1);
        int ans = 0;
        c[0] = -1;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == '0' && t[i] == '0') {
                if(c[i - 1] == 0)
                    ans += 2, c[i] = 2;
                else ++ans, c[i] = 1;
            } else if(s[i] == '1' && t[i] == '1') {
                if(c[i - 1] == 1)
                    c[i] = 2, ++ans;
                else c[i] = 0;
            } else {
                c[i] = 2;
                ans += 2;
            }
        }
        printf("%d\n", ans);
    } return 0;
}