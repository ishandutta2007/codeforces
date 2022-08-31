#include <cstdio>
#include <cassert>
using namespace std;

const int N = 1000500;

int A[N];

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int pos[2] = {0, 1};
    assert(n % 2 == 0);
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        if (x == 1) {
            int y;
            scanf("%d", &y);
            pos[0] += y;
            pos[1] += y;
            pos[0] = (pos[0] % n + n) % n;
            pos[1] = (pos[1] % n + n) % n;
        } else {
            pos[0] ^= 1;
            pos[1] ^= 1;
        }
    }
    for (int i = 0; i < n / 2; i++) {
        A[(pos[0] + 2 * i) % n] = 2 * i;
        A[(pos[1] + 2 * i) % n] = 2 * i + 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", 1 + A[i]);
    }
    printf("\n");
}