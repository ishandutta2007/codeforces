#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 5005;
ll d[maxn][maxn];
int S, E;
int X[maxn];
int A[maxn];
int B[maxn];
int C[maxn];
int D[maxn];
int n;

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    cin >> n >> S >> E;
    --S, --E;
    forn (i, n) cin >> X[i];
    forn (i, n) cin >> A[i];
    forn (i, n) cin >> B[i];
    forn (i, n) cin >> C[i];
    forn (i, n) cin >> D[i];
    forn (i, maxn)
        forn (j, maxn)
            d[i][j] = infl;
    d[0][0] = 0;
    forn (i, n) {
        forn (right, n + 1) {
            if (d[i][right] == infl)
                continue;
            int left = right;
            if (S < i && E >= i)
                --left;
            if (S >= i && E < i)
                ++left;
            if (right == 0 && left == 0 && i != 0)
                continue;
            //cerr << i << ' ' << right << ' ' << d[i][right] << '\n';
            if (left < 0)
                continue;

            forn (from, 2) {
                forn (to, 2) {
                    if (from == 0 && right == 0)
                        continue;
                    if (to == 0 && left == 0)
                        continue;
                    int nright = right;
                    if (from == 0 && i != S)
                        --nright;
                    if (to == 1 && i != E)
                        ++nright;
                    if (nright < 0)
                        continue;

                    ll nval = d[i][right];
                    if (i > 0)
                        nval += ll(right + left) * ll(X[i] - X[i - 1]);
                    if (i != S) {
                        if (from == 0)
                            nval += A[i];
                        else
                            nval += B[i];
                    }
                    if (i != E) {
                        if (to == 0)
                            nval += C[i];
                        else
                            nval += D[i];
                    }
                    d[i + 1][nright] = min(d[i + 1][nright], nval);
                }
            }
        }
    }
    cout << d[n][0] << '\n';
}