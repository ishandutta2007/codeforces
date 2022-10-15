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
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <ll, ll> pii;
const int N = 5e5 + 5;
 
int n; ll a[N];
std::priority_queue <pii> q;
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
    int test_case_cnt = 1; //rd(test_case_cnt);
    while(test_case_cnt--) {
        int n; rd(n);
        for(int i = 1; i <= n; ++i) rd(a[i]);
        q.push(mkp(a[1] - 1, 0));
        for(int i = 2; i <= n; ++i) {
            ll s_mx = -1;
            while(!q.empty() && q.top().fi >= a[i]) {
                pii j = q.top(); q.pop();
                ll r = j.fi, s = j.se;
                q.push(mkp(r % a[i], s + (i - 1) * (r - r % a[i])));
                s_mx = std::max(s_mx, s + (i - 1) * (r - r % a[i] - a[i]));
            }
            if(~s_mx) q.push(mkp(a[i] - 1, s_mx));
        }
        ll ans = 0;
        while(!q.empty()) {
            pii j = q.top(); q.pop();
            ll r = j.fi, s = j.se;
            ans = std::max(ans, r * n + s);
        }
        printf("%lld\n", ans);
    } return 0;
}