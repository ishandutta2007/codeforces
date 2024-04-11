#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef long long llong;

const int N = 10500;

llong D[N];
llong nD[N];

const llong inf = 1e16;

int P[N], S[N];

inline void relax(llong& x, llong y) {
    if (x > y)
        x = y;
}


int main() {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &P[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i + 1; j++)
            nD[j] = inf;
        llong xc = 0;
        for (int x = 0; x <= i; x++) {
            relax(nD[x], D[x] + P[i] + xc);
            relax(nD[x + 1], D[x] + S[i]);
            xc += c;
        }
        memcpy(D, nD, sizeof(llong) * (i + 2));
    }
    llong ans = inf;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, D[i]);
    }
    printf("%lld\n", ans);
}