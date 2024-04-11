#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, a[N], b[N];

vector <int> c[N];

ll ans, cur;

ll ask_(int x) {
    return 1ll*(a[x] - b[x])*b[x];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        c[i].resize(m + 1);

        for (int j = 1; j <= m; j++) {
            scanf("%d", &c[i][j]);
            a[c[i][j]]++;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            cur -= ask_(c[i][j]);
            b[c[i][j]]++;
            cur += ask_(c[i][j]);
        }

        ans += cur;
    }

    memset(b, 0, sizeof(b));
    cur = 0;

    for (int j = 1; j < m; j++) {
        for (int i = 1; i <= n; i++) {
            cur -= ask_(c[i][j]);
            b[c[i][j]]++;
            cur += ask_(c[i][j]);
        }

        ans += cur;
    }

    printf("%lld\n", ans);
}