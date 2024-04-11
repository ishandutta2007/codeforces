#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T, m, a[3];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d%d", &a[0], &a[1], &a[2], &m);
        sort(a, a + 3);

        int l = 0, r = 1e9;

        l = max(l, a[2] - 1 - a[1] - a[0]);
        r = a[0] + a[1] + a[2] - 3;

        printf("%s\n", l <= m && m <= r ? "YES" : "NO");
    }
}