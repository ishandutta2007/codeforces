#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long llong;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()

const int MOD = 1000 * 1000 * 1000 + 7;

inline int mul(int a, int b) {
    return 1ll * a * b % MOD;
}

inline int add(int a, int b) {
    return ((a + b >= MOD) ? a + b - MOD : a + b);
}

const int N = 405;

int D[N][N];

int main() {
#ifdef LOCAL
    assert(freopen(".in", "r", stdin));
#endif
    int maxk;
    scanf("%d", &maxk);

    D[1][0] = 1;
    D[1][1] = 1;

    for (int k = 2; k <= maxk; k++) {
        D[k][0] = 1;
        for (int c = 1; c <= maxk - k + 1; c++) {
            int nez = 0;
            for (int a = 0; a <= c; a++) {
                int b = c - a;
                nez = add(nez, mul(D[k - 1][a], D[k - 1][b]));
            }

            int leftrightjoin = 0;
            for (int a = 1; a <= c; a++) {
                int b = c + 1 - a;
                int cur = a * b;
                cur = mul(cur, D[k - 1][a]);
                cur = mul(cur, D[k - 1][b]);
                leftrightjoin = add(leftrightjoin, cur);
            }

            int prisov = 0;
            for (int a = 1; a <= c; a++) {
                int join = mul(a * (a + 1), D[k - 1][a + 1]);
                int just = mul(2 * a, D[k - 1][a]);
                int cur = add(join, just);
                int b = c - a;
                cur = mul(cur, D[k - 1][b]);
                prisov = add(prisov, cur);
            }

            int singleroot = 0;
            for (int a = 0; a <= c - 1; a++) {
                int b = c - a - 1;
                singleroot = add(singleroot, mul(D[k - 1][a], D[k - 1][b]));
            }

            D[k][c] = add(D[k][c], nez);
            D[k][c] = add(D[k][c], mul(2, leftrightjoin));
            D[k][c] = add(D[k][c], mul(2, prisov));
            D[k][c] = add(D[k][c], singleroot);
        }
    }
   
/*    for (int k = 1; k <= maxk; k++) {
        for (int c = 0; c <= maxk + 1; c++) {
            fprintf(stderr, "%d ", D[k][c]);
        }
        fprintf(stderr, "\n");
    }*/

    int ans = D[maxk][1];
    printf("%d\n", ans);

}