#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 1e5 + 10;

int T, n, a[N], b[N], c[N];

bool solve_() {
    b[1] = a[1];

    for (int i = 2; i <= n; i++) {
        b[i] = max(b[i - 1], a[i]);
    }

    c[n] = a[n];

    for (int i = n - 1; i; i--) {
        c[i] = min(c[i + 1], a[i]);
    }

    for (int i = 1; i < n; i++) {
        if (b[i] > c[i + 1]) {
            return 1;
        }
    }

    return 0;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        printf("%s\n", solve_() ? "YES" : "NO");
    }
}