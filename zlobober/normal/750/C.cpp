#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200500;

const int inf = 200 * 1000 * 1000;

int main() {
    int n;
    scanf("%d", &n);
    int l = -inf, r = inf;
    int sd = 0;
    for (int i = 0; i < n; i++) {
        int d, t;
        scanf("%d %d", &d, &t);
        if (t == 1) {
            l = max(l, 1900 - sd);
        } else {
            r = min(r, 1899 - sd);
        }
        sd += d;
    }
    if (l > r) {
        puts("Impossible");
    } else if (r >= inf / 2) {
        puts("Infinity");
    } else {
        printf("%d\n", r + sd);
    }
    return 0;
}