#include <cstdio>
using namespace std;

bool can(int x, int n, int m) {
    int a = x / 2;
    int b = x / 3;
    int c = x / 6;
    a -= c;
    b -= c;
    return a + b + c >= n + m && a + c >= n && b + c >= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int l = 0, r = 1e8;
    while (r - l > 1) {
        int q = (l + r) / 2;
        if (can(q, n, m))
            r = q;
        else
            l = q;
    }
    printf("%d\n", r);
}