#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 3e5 + 10;

int n, m, T, cnt, a[N], b[N], c[N], t[N], tag, id[N], tot;

ll ans;

set <int> s[N];

set <int> :: iterator it;

vector <int> e[N];

int id_(int x) {
    return lower_bound(b + 1, b + cnt + 1, x) - b;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m), ans = cnt = tot = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }

        sort(b + 1, b + n + 1);
        cnt = unique(b + 1, b + n + 1) - b - 1;

        for (int i = 1; i <= cnt; i++) {
            c[i] = 0;
            s[i].clear();
            e[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            c[id_(a[i])]++;
        }

        for (int i = 1; i <= cnt; i++) {
            if (!s[c[i]].size()) {
                id[++tot] = c[i];
            }

            s[c[i]].insert(i);
        }

        for (int u, v, i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            u = id_(u), v = id_(v);
            e[u].push_back(v);
            e[v].push_back(u);
        }

        for (int i = 1; i <= cnt; i++) {
            ++tag;

            for (int j : e[i]) {
                t[j] = tag;
            }

            t[i] = tag;

            for (int j = 1; j <= tot; j++) {
                int k = id[j];
                it = --s[k].end();

                while (1) {
                    int x = *it;

                    if (t[x] != tag) {
                        ans = max(ans, 1ll*(b[i] + b[x])*(c[i] + c[x]));
                        break;
                    }

                    if (it == s[k].begin()) {
                        break;
                    }

                    it--;
                }
            }
        }

        printf("%lld\n", ans);
    }
}