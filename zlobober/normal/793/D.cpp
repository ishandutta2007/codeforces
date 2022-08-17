#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

const int N = 100;
const int M = 2050;

int A[N][N];

const int inf = 1000500;

int D[N][N][N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            A[i][j] = inf;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, x;
        scanf("%d %d %d", &a, &b, &x);
        A[a][b] = min(A[a][b], x);
    }

    if (k > n) {
        puts("-1");
        return 0;
    }

    for (int d = 0; d <= n + 1; d++) {
        for (int a = 0; a <= n + 1; a++) {
            for (int b = 0; b <= n + 1; b++) {
                D[d][a][b] = inf;
            }
        }
    }

    for (int a = 1; a <= n; a++) {
        for (int b = 0; b <= n + 1; b++) {
            D[1][a][b] = 0;
        }
    }

    for (int d = 2; d <= k; d++) {
        for (int a = 1; a <= n; a++) {
            for (int b = 0; b <= n + 1; b++) {
                if (a == b)
                    continue;
                int add = (b > a) - (b < a);
                for (int i = a + add; i != b; i += add) {
                    assert(1 <= a && a <= n);
                    assert(1 <= i && i <= n);
                    assert(a != i);
                    int v1 = A[a][i] + D[d - 1][i][a];
                    int v2 = A[a][i] + D[d - 1][i][b];
                    D[d][a][b] = min({D[d][a][b], v1, v2});
                }
            }
        }
    }
    int ans = inf;
    for (int a = 1; a <= n; a++) {
        for (int b = 0; b <= n + 1; b++) {
            if (a != b)
                ans = min(ans, D[k][a][b]);
        }
    }
    if (ans >= inf)
        ans = -1;
    printf("%d\n", ans);
}