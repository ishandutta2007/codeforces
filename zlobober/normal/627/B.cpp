#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200500;

typedef long long llong;

int F1[N], F2[N], V1[N], V2[N];
int V[N];

llong get1(int x) {
    llong ans = 0;
    for (; x >= 0; x &= (x + 1), --x)
        ans += F1[x];
    return ans;
}

llong get2(int x) {
    llong ans = 0;
    for (; x < N; x |= x + 1)
        ans += F2[x];
    return ans;
}

void add1(int x, int v) {
    for (; x < N; x |= x + 1)
        F1[x] += v;
}

void add2(int x, int v) {
    for (; x >= 0; x &= (x + 1), --x)
        F2[x] += v;
}

int main() {
    int n, k, a, b, q;
    scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int t, dv;
            scanf("%d %d", &t, &dv);
            --t;
            int nv = V[t] + dv;
            int nv1 = min(nv, b);
            int delta1 = nv1 - V1[t];
            int nv2 = min(nv, a);
            int delta2 = nv2 - V2[t];
            V[t] = nv;
            V1[t] = nv1;
            V2[t] = nv2;
            add1(t, delta1);
            add2(t, delta2);
        } else {
            int p;
            scanf("%d", &p);
            --p;
            llong ans1 = get1(p - 1);
            llong ans2 = get2(p + k);
            printf("%lld\n", ans1 + ans2);
        }
    }
}