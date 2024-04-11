#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

typedef pair<int, int> pii;

const int maxn = 150;
int a[maxn], b[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int n;
    cin >> n;
    forn (i, n) {
        int a, d;
        cin >> a >> d;
        ::a[i] = a, ::b[i] = a + d;
    }
    int res = 0;
    forn (i, n)
        forn (j, i) {
            pii A{a[i], -i};
            pii B{b[i], -i};
            pii C{a[j], -j};
            pii D{b[j], -j};
            bool c1 = (A < C) != (B < C);
            bool c2 = (C < A) != (D < A);
            bool ne = (A < C) == (B < D);
            if (!ne)
                ++res;
            else if (c1 || c2) {
                res += 2;
                //cerr << i + 1 << ' ' << j + 1 << '\n';
            }
        }
    cout << res << '\n';
}