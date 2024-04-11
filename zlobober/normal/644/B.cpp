#include <cstdio>
using namespace std;

typedef long long llong;

const int N = 200500;
llong E[N];
int lpt = 0, rpt = 0;
int Q[N];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        E[i] = -1;
        llong a, b;
        scanf("%lld %lld", &a, &b);
        while (lpt != rpt && E[Q[lpt]] <= a)
            lpt++;
        if (rpt - lpt <= q) {
            E[i] = b + ((lpt != rpt) ? E[Q[rpt - 1]] : a);
            Q[rpt++] = i;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%lld ", E[i]);
    printf("\n");
}