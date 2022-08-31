#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 100500;
int Q[N];
int num[N];
int par[N];

int get(int x) {
    return (x == par[x]) ? x : (par[x] = get(par[x]));
}

bool merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return false;
    par[a] = b;
    num[b] += num[a];
    return true;
}

int sz[N];

int c2(int x) {
    return x * (x - 1) / 2;
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        par[i] = i, num[i] = 1;
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        --x;
        Q[i] = x;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        merge(a, b);
    }
    int sumc2 = 0;
    int sumn = 0;
    for (int i = 0; i < k; i++) {
        int x = get(Q[i]);
        sumc2 += c2(num[x]);
        sumn += num[x];
    }
    int rem = n - sumn;
    assert(rem >= 0);
    int best = 0;
    for (int i = 0; i < k; i++) {
        int x = get(Q[i]);
        best = max(best, sumc2 - c2(num[x]) + c2(num[x] + rem));
    }
    printf("%d\n", best - m);
}