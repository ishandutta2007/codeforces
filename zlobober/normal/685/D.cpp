#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;

const int N = 100500;
const int M = 305 * N;

int X[N], Y[N];

int CY[N];
int MY[N];
int cpt = 0;

int last[M];
int val[M];

typedef long long llong;

llong cnt[N];

void upd(int x, int y, int d) {
    cnt[val[y]] += (x - last[y]);
    last[y] = x;
    val[y] += d;
}

int k;


int comp(int y) {
    int prv = upper_bound(CY, CY + cpt, y) - CY - 1;
    if (prv == -1 || y - CY[prv] >= k)
        return -1;
    else
        return y - CY[prv] + MY[prv];
}

struct ev {
    int x, y, d;
    ev(int _x, int _y, int _d) {
        x = _x, y = _y, d = _d;
    }
    ev() {}
    friend bool operator <(ev a, ev b) {
        return a.x < b.x;
    }
};

ev E[2 * N];

int main() {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &X[i], &Y[i]);
    }
    memcpy(CY, Y, sizeof(int) * n);
    sort(CY, CY + n);
    cpt = unique(CY, CY + n) - CY;
    for (int i = 1; i < cpt; i++) {
        MY[i] = MY[i - 1] + min(k, CY[i] - CY[i - 1]);
    }
    for (int i = 0; i < n; i++) {
        E[2 * i] = ev(X[i], Y[i], 1);
        E[2 * i + 1] = ev(X[i] + k, Y[i], -1);
    }
    sort(E, E + 2 * n);
    for (ev e : E) {
        int cy = comp(e.y);
        for (int y = cy; y < cy + k; y++)
            upd(e.x, y, e.d);
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", cnt[i]);
    }
    printf("\n");
}