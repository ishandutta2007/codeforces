#include <bits/stdc++.h>
 
#define gc() getchar()
template <typename T> inline void rd(T& x) {
    int si = 1; char c = gc(); x = 0;
    while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
    while(isdigit(c)) x = x * 10 + c - 48, c = gc();
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
typedef unsigned ui;
const int N = 5e5 + 5, Inf = 0x3f3f3f3f, Mod = 998244353;
const ll InfLL = 0x3f3f3f3f3f3f3f3fLL;
 
int n, p_cnt; ll p[N], a[N];
void GetFactor(ll x) {
    for(ll j = 2; j * j <= x; ++j) {
        if(x % j == 0) {
            p[++p_cnt] = j;
            while(x % j == 0) x /= j;
        }
    }
    if(x != 1) p[++p_cnt] = x;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; //rd(test_case_cnt);
    while(test_case_cnt--) {
        srand(time(0));
        rd(n);
        for(int i = 1; i <= n; ++i) rd(a[i]);
        for(int i = 1; i <= 30; ++i) {
            int x = ((ui)rand() ^ (rand() << 15)) % n + 1;
            GetFactor(a[x]);
            if(a[x] - 1) GetFactor(a[x] - 1);
            GetFactor(a[x] + 1);
        }
        std::sort(p + 1, p + p_cnt + 1);
        p_cnt = std::unique(p + 1, p + p_cnt + 1) - p - 1;
        ll ans = InfLL;
        for(int i = 1; i <= p_cnt; ++i) {
            ll cur_ans = 0;
            for(int j = 1; j <= n; ++j) {
                ll al = (a[j] / p[i]) * p[i], ar = ((a[j] - 1) / p[i] + 1) * p[i];
                if(al) cur_ans += std::min(a[j] - al, ar - a[j]);
                else cur_ans += ar - a[j];
                if(cur_ans > ans) break;
            }
            ans = std::min(ans, cur_ans);
        }
        printf("%lld\n", ans);
    } return 0;
}