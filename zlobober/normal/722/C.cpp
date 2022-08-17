#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long llong;

const int N = 100500;

typedef long long llong;

int par[N];
int rnk[N];
llong S[N];

bool on[N];
int A[N];
int P[N];

int get(int x) {
    return (x == par[x]) ? x : ((par[x] = get(par[x])));
}

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (rnk[a] > rnk[b])
        swap(a, b);
    if (rnk[b] == rnk[a])
        rnk[b]++;
    par[a] = b;
    S[b] += S[a];
}

llong ans[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        --p;
        P[i] = p;
    }
    for (int i = 0; i < n; i++)
        par[i] = i;

    llong cans = 0;
    ans[n - 1] = 0;
    for (int i = n - 1; i > 0; i--) {
        int p = P[i];
        on[p] = true;
        S[p] = A[p];
        if (p + 1 < n && on[p + 1])
            merge(p, p + 1);
        if (p - 1 >= 0 && on[p - 1])
            merge(p, p - 1);
        ans[i - 1] = cans = max(cans, S[get(p)]);
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", ans[i]);
    }
}