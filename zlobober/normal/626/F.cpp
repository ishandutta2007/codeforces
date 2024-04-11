#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 205;
const int K = 1050;

const int MOD = 1000 * 1000 * 1000 + 7;

inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
}
inline void add(int& x, int y) {
    if ((x += y) >= MOD) {
        x -= MOD;
    }
}


int D[N][K];
int nD[N][K];

int A[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    D[0][0] = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A + n);
    for (int i = 0; i < n - 1; i++) {
        int len = A[i + 1] - A[i];
        for (int nbal = 0; nbal <= i + 1; nbal++) {
            for (int nsum = 0; nsum <= k; nsum++) {
                nD[nbal][nsum] = 0;
            }
        }
        for (int bal = 0; bal <= i; bal++) {
            for (int sum = 0; sum <= k; sum++) {
                if (!D[bal][sum])
                    continue;
                {
                    int nbal = bal;
                    int nsum = sum + len * nbal;
                    if (nsum <= k)
                        add(nD[nbal][nsum], mul(D[bal][sum], (bal + 1)));
                }
                {
                    int nbal = bal - 1;
                    int nsum = sum + len * nbal;
                    if (nbal >= 0 && nsum <= k)
                        add(nD[nbal][nsum], mul(D[bal][sum], bal));
                }
                {
                    int nbal = bal + 1;
                    int nsum = sum + len * nbal;
                    if (nsum <= k)
                        add(nD[nbal][nsum], D[bal][sum]);
                }
            }
        }
        for (int nbal = 0; nbal <= i + 1; nbal++) {
            for (int nsum = 0; nsum <= k; nsum++) {
                D[nbal][nsum] = nD[nbal][nsum];
            }
        }
    }
    int ans = 0;
    for (int sum = 0; sum <= k; sum++) {
        add(ans, D[0][sum]);
        add(ans, D[1][sum]);
    }
    printf("%d\n", ans);
}