#include <bits/stdc++.h>
using namespace std;
mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
inline int randnum(int n) {return mt() % n;}
template <class T> inline void rd(T &x) {
    x = 0; T f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
    while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    x *= f;
} 

typedef long long ll;
const int N = 200005;
int n;
ll ans = 1e18, a[N];

inline void calc(ll p) {
    ll sum = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] < p) sum += p - a[i] % p;
        else sum += min(a[i] % p, p - a[i] % p);
    }
    ans = min(ans, sum);
}

inline void check(ll x) {
    if(!x) return;
    for(ll p = 2, xx = x; p * p <= xx; ++p) {
        if(x % p == 0) {
            calc(p);
            while(x % p == 0) x /= p;
        }
    }
    if(x > 1) calc(x);
}

int main() {
    rd(n); for(int i = 1; i <= n; ++i) rd(a[i]);
    random_shuffle(a + 1, a + n + 1, randnum);
    for(int i = 1; i <= min(20, n); ++i) check(a[i] - 1), check(a[i]), check(a[i] + 1);
    printf("%lld\n", ans);
    return 0;
}