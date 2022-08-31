#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long llong;

const int N = 400500;
llong A[N];
llong B[N];

inline llong mymod2(llong x) {
    if (x % 2 == 0)
        return 0;
    else 
        return 1;
}

inline llong mydiv2(llong x) {
    if (x >= 0)
        return x / 2;
    else {
        if (x % 2 == 0)
            return x / 2;
        else
            return x / 2 - 1;
    }
}

void buildB() {
    for (int i = 0; i < N; i++)
        B[i] = A[i];
    for (int i = 0; i < N - 1; i++) {
        B[i + 1] += mydiv2(B[i]);
        B[i] = mymod2(B[i]);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) {
        int x;
        scanf("%d", &x);
        A[i] = x;
    }
    buildB();
    if (B[N - 1]) {
        for (int i = 0; i <= n; i++)
            A[i] = -A[i];
        buildB();
    }
    int fst = 0;
    while (fst != N && B[fst] == 0) {
        fst++;
    }
    assert(fst != N);
    llong cur = 0;
    bool bad = false;
    for (int i = fst; i < N; i++) {
        if (B[i]) {
            int p = i - fst;
            if (p > 40) {
                bad = true;
                break;
            }
            cur += 1ll << p;

        }
    }
    int cnt = 0;
    if (!bad) {
        for (int i = fst; i >= 0; i--) {
            if (cur > (1ll << 32)) // 4e9
                break;
            llong nA = A[i] - cur;
            if (abs(nA) <= k && (i != n || nA != 0) && (i <= n))
                cnt++;
            cur <<= 1;
        }
    }
    printf("%d\n", cnt);
}