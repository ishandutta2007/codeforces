#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

int n, m;
int ln, lm;

int pow7(int a) {
    int res = 1;
    forn (i, a)
        res *= 7;
    return res;
}

int a[100];
set<pair<int, int>> S;

void check() {
    int N = 0;
    forn (i, ln) {
        N += pow7(i) * a[i];
    }
    int M = 0;
    forn (i, lm) {
        M += pow7(i) * a[i + ln];
    }
    if (N < n && M < m)
        S.emplace(N, M);
}

int main() {
    #ifdef LOCAL
    assert(freopen("a.in", "r", stdin));
    #else
    #endif
    cin >> n >> m;
    ln = 1, lm = 1;
    while (pow7(ln) < n)
        ++ln;
    while (pow7(lm) < m)
        ++lm;
    if (ln + lm > 7) {
        cout << 0 << '\n';
        return 0;
    }
    forn (i, 7)
        a[i] = i;
    do {
        check();
    } while (next_permutation(a, a + 7));
    cout << S.size() << '\n';
}