#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, m, T, f[N][3], a[N], len, rk[N];

ll s[N], t[N];

vector <int> b[N];

struct Node {
    ll a, b;
    int id;

    bool operator < (const Node &tmp) const {
        return a*tmp.b < b*tmp.a;
    }
} c[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= m; i++) {
            b[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int k, i = 1; i <= m; i++) {
            scanf("%d", &k), b[i].resize(k);
            c[i].id = i, c[i].b = k, c[i].a = 0;

            for (int j = 0; j < k; j++) {
                scanf("%d", &b[i][j]);
                c[i].a += b[i][j];
            }
        }

        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        reverse(a + 1, a + m + 1);
        a[m + 1] = 1e7, a[0] = 0;
        sort(c + 1, c + m + 1);
        
        for (int i = 1; i <= m; i++) {
            rk[c[i].id] = i;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 3; j++) {
                f[i][j] = !((Node) {a[i + j - 1], 1, 0} < c[i]) ? f[i - 1][j] : i;
            }
        }

        for (int i = 1; i <= m; i++) {
            int x = rk[i];
            len = b[i].size();
            t[len + 1] = 0;

            for (int j = 0; j < len; j++) {
                s[j + 1] = b[i][j] + s[j];
                t[j + 1] = b[i][j];
            }

            for (int j = len; j; j--) {
                t[j] += t[j + 1];
            }

            for (int j = 1; j <= len; j++) {
                ll sum = s[j - 1] + t[j + 1];
                Node tmp = (Node) {sum, len - 1, i};
                int y = lower_bound(c + 1, c + m + 1, tmp) - c;
                y -= y > x;
                bool ok = 1;

                if (x <= y) {
                    ok = !f[x - 1][1] && f[m][1] <= y && f[y][0] <= x && !((Node) {a[y], 1, 0} < tmp);
                } else {
                    ok = !f[y - 1][1] && f[m][1] <= x && f[x - 1][2] < y && !((Node) {a[y], 1, 0} < tmp);
                }

                putchar(ok ? '1' : '0');
            } 
        }

        puts("");
    }
}