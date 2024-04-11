#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

inline void relax(int& x, int y) {
    if (x < y)
        x = y;
}

const int N = 16;

int R[N], B[N];
char C[N];

const int E = 150;
int D[1 << N][E];

const int inf = 1e7 + 42;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c %d %d", &C[i], &R[i], &B[i]);
    }
    for (int msk = 0; msk < (1 << n); msk++) {
        for (int i = 0; i < E; i++) {
            D[msk][i] = -inf;
        }
    }
    D[0][0] = 0;
    for (int msk = 0; msk < (1 << n); msk++) {
        int cA = 0, cB = 0;
        for (int z = 0; z < n; z++) {
            if ((msk >> z) & 1) {
                ++((C[z] == 'R') ? cA : cB);
            }
        }
        for (int i = 0; i < E; i++) {
            if (D[msk][i] < 0)
                continue;
            for (int z = 0; z < n; z++) {
                if ((msk >> z) & 1) {
                    continue;
                }
                assert(i + min(cA, R[z]) < E);
                relax(D[msk ^ (1 << z)][i + min(cA, R[z])], D[msk][i] + min(cB, B[z]));
            }
        }
    }
    int sr = accumulate(R, R + n, 0);
    int sb = accumulate(B, B + n, 0);
    int ans = inf * n;
    for (int i = 0; i < E; i++) {
        if (D[(1 << n) - 1][i] < 0)
            continue;
        int qr = sr - i;
        int qb = sb - D[(1 << n) - 1][i];
        assert(qr >= 0 && qb >= 0);
        ans = min(ans, max(qr, qb));
    }
    printf("%d\n", ans + n);
}