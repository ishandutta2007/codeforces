#include <cstdio>
#include <algorithm>
#include <map>
#include <memory.h>
#include <cassert>
using namespace std;

typedef long long llong;

const int N = 100500;
const int K = 55;

llong V[N];

inline int deg(llong x) {
    assert(x >= 1);
    int k = 0;
    while ((1ll << k) < x)
        ++k;
    if ((1ll << k) == x)
        return k;
    return ~k;
}

int cnt[K];
int rem[K];

int _cnt[K];

int lst[N];
int bad[N];

int n;

int A[K], B[K];

bool check(int m) {
    memcpy(cnt, _cnt, sizeof(cnt));
    for (int i = 0; i < m; i++) {
        lst[i] = 0;
        while (cnt[lst[i]] > 0)
            --cnt[lst[i]], ++lst[i];
        --lst[i];
        assert(lst[i] >= 0);
    }
    int k = 0;
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < cnt[i]; j++)
            bad[k++] = i;
        for (int j = 0; j < rem[i]; j++)
            bad[k++] = i;
    }
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    for (int i = 0; i < m; i++) {
        A[lst[i]]++;
    }
    for (int i = 0; i < k; i++) {
        B[bad[i]]++;
    }
    for (int i = K - 1; i >= 0; i--) {
        int& here = B[i];
        for (int j = max(0, i - 1); j < K; j++) {
            if (here == 0)
                break;
            int mn = min(here, A[j]);
            here -= mn;
            A[j] -= mn;
        }
        if (here != 0)
            return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &V[i]);
    }
    for (int i = 0; i < n; i++) {
        int d = deg(V[i]);
        if (d >= 0)
            cnt[d]++;
        else {
            d = ~d;
            rem[d]++;
        }
    }
    memcpy(_cnt, cnt, sizeof(cnt));
    int mx = cnt[0];
    int l = 0, r = mx + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    int mn = r;
    for (int i = mn; i <= mx; i++) {
        printf("%d ", i);
    }
    if (mn > mx)
        printf("-1");
    printf("\n");
    /*fprintf(stderr, "mn = %d, mx = %d\n", mn, mx);
    for (int i = 0; i <= mx; i++) {
        char c = "01"[check(i)];
        fprintf(stderr, "%d -> %c\n", i, c);
        assert((c == '1')  == (i >= mn && i <= mx));
    }*/

}