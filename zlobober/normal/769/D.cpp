#include <cstdio>
#include <cassert>
using namespace std;

const int M = 1 << 14;
int xors[M];
int cnt[M];
int num[M];

typedef long long llong;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
    }
    int pt = 0;
    for (int i = 0; i < M; i++) {
        if (__builtin_popcount(i) == k) {
            xors[pt++] = i;
        }
    }
    llong ans = 0;
    int iter = 0;
    for (int x = 0; x < M; x++) {
        if (cnt[x]) {
            for (int j = 0; j < pt; j++) {
                int y = x ^ xors[j];
                num[x] += cnt[y];
                iter++;
            }
            ans += (llong)cnt[x] * num[x];
        }
    }
    if (k == 0) {
        ans -= n;
    }
    assert(ans >= 0 && ans % 2 == 0);
    ans /= 2;
    printf("%lld\n", ans);
    fprintf(stderr, "iter = %d\n", iter);
}