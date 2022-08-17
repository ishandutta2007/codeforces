#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100500;

int A[N];

typedef long long llong;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    int mn = *min_element(A, A + n);
    llong sum = 0;
    bool bad = false;
    for (int i = 0; i < n; i++) {
        if ((A[i] - mn) % k != 0)
            bad = true;
        sum += (A[i] - mn) / k;
    }
    if (bad)
        sum = -1;
    printf("%lld\n", sum);

}