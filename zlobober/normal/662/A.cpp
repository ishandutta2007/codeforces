#include <cstdio>
#include <bitset>
using namespace std;

const int L = 60;
const int N = 500500;

typedef long long llong;

bitset<N> B[L];

int n;

int main() {
    scanf("%d", &n);
    llong init = 0;

    for (int i = 0; i < n; i++) {
        llong a, b;
        scanf("%lld %lld", &a, &b);
        init ^= a;
        llong x = a ^ b;
        for (int j = 0; j < L; j++)
            B[j][i] = (x >> j) & 1ll;
    }
    for (int j = 0; j < L; j++)
        B[j][n] = (init >> j) & 1ll;

    int pt = 0;
    for (int j = 0; j <= n; j++) {
        int ind = -1;
        for (int i = pt; i < L; i++) {
            if (B[i][j]) {
                ind = i;
            }
        }
        if (ind == -1)
            continue;
        swap(B[ind], B[pt]);
        for (int i = pt + 1; i < L; i++) {
            if (B[i][j])
                B[i] ^= B[pt];
        }
        pt++;
    }

    bool bad = false;

    for (int i = 0; i < L; i++) {
        if (B[i][n] == 1) {
            B[i][n] = 0;
            if (!B[i].any()) {
                bad = true;
            }
        }
    }

    if (bad) {
        printf("1/1\n");
    } else {
        printf("%lld/%lld\n", (1ll << pt) - 1, 1ll << pt);
    }
}