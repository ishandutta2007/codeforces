#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1030;
int cnt[maxn];
int cnt2[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, k, x;
    cin >> n >> k >> x;
    forn (i, n) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    forn (iter, k) {
        int carry = 1;
        forn (i, maxn) {
            int m = (carry + cnt[i]) >> 1;
            cnt2[i] += cnt[i] - m;
            cnt2[i ^ x] += m;
            carry ^= (cnt[i] & 1);
        }
        memcpy(cnt, cnt2, sizeof(cnt));
        memset(cnt2, 0, sizeof(cnt2));
    }
    int nn = 0;
    forn (i, maxn)
        forn (j, cnt[i]) {
            ++nn;
            //cerr << i << ' ';
        }
    //cerr << '\n';
    assert(nn == n);
    int mx = maxn - 1;
    while (cnt[mx] == 0)
        --mx;
    int mn = 0;
    while (cnt[mn] == 0)
        ++mn;
    cout << mx << ' ' << mn << '\n';
}