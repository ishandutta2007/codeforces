#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long llong;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

const int N = 105;
int A[N];

const int K = 300 * 1000;
const int L = 6 * 1000;
const int MAX = 1000 * 1000 * 1000;

int n;

inline llong f(llong d) {
    llong val = 0;
    for (int i = 0; i < n; i++) {
        llong rem = A[i] % d;
        if (rem != 0)
            val += d - rem;
    }
    return val;
}

int main() {
#ifdef LOCAL
    assert(freopen(".in", "r", stdin));
#endif
    llong k;
    scanf("%d %lld", &n, &k);
    vector<llong> interesting;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    assert(1ll * K * L >= 1.5 * MAX);
    for (int i = 1; i <= K; i++) {
        interesting.emplace_back(i);
    }
    for (int k = 1; k <= L; k++) {
        for (int i = 0; i < n; i++) {
            llong d = (A[i] + k - 1) / k;
            interesting.emplace_back(d);
        }
    }
    fprintf(stderr, "interesting.size() = %d\n", (int)interesting.size());
    sort(interesting.begin(), interesting.end());
    interesting.resize(unique(interesting.begin(), interesting.end()) - interesting.begin());
    llong ok_d = -1;
    fprintf(stderr, "interesting.size() = %d\n", (int)interesting.size());
    interesting.emplace_back(((llong)2e11) + 142);
    
    for (int i = 0; i < (int)interesting.size() - 1; ++i) {    
        llong x0 = interesting[i];
        llong xnext = interesting[i + 1] - 1;
        llong x1 = x0 + 1;
        llong y0 = f(x0);
        if (y0 <= k) {
            ok_d = x0;
        }
        if (x0 == xnext) {
            continue;
        } else {
            llong y1 = f(x1);
            assert(y1 >= y0);
            if (y0 > k) {
                continue;
            }
            llong dy = y1 - y0;
            llong ynext = y0 + (xnext - x0) * dy;
#ifdef LOCAL42
            assert(ynext == f(xnext));
#endif // LOCAL42
            llong d = xnext;
            if (ynext > k) {
                d = x0 + ((k - y0) / dy);
            }
            ok_d = d;
        }
    }
    assert(ok_d != -1);
    printf("%lld\n", ok_d);
}