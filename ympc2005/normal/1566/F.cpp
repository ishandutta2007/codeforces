#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 3e5 + 10;

int T, n, m;

ll a[N], f[N][2];

vector <int> id[N];

struct Node {
    ll l, r;

    bool operator < (const Node tmp) const {
        return l == tmp.l ? r > tmp.r : l < tmp.l;
    } 
} b[N];

void init_() {
    scanf("%d%d", &n, &m), a[0] = -1e12;

    for (int i = 0; i <= n; i++)
        id[i].clear();

    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    
    sort(a + 1, a + n + 1);
    
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld", &b[i].l, &b[i].r); 
        int pos = lower_bound(a + 1, a + n + 1, b[i].l) - a;

        if (pos <= n && a[pos] <= b[i].r)
            i--, m--;
    }

    sort(b + 1, b + m + 1);

    ll pos = 1e12;

    for (int i = m; i; i--)
        if (b[i].r < pos) {
            pos = b[i].r;
            int x = lower_bound(a + 1, a + n + 1, b[i].l) - a - 1;
            id[x].push_back(i); 
        }
    
    for (int i = 0; i <= n; i++) 
        reverse(id[i].begin(), id[i].end());
}

void work_() {
    f[0][0] = f[0][1] = 0;

    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < 2; j++) {
            f[i][j] = 1e18;

            for (int k = 0; k < 2; k++) {
                if (id[i - 1].size()) {
                    ll res = 1e18;
                    int tot = id[i - 1].size();
                    res = min(res, (j + 1)*(a[i] - b[id[i - 1][0]].r));
                    res = min(res, (2 - k)*(b[id[i - 1][tot - 1]].l - a[i - 1]));
                    
                    for (int x = 0; x < tot - 1; x++)
                        res = min(res, (j + 1)*(a[i] - b[id[i - 1][x + 1]].r) + (2 - k)*(b[id[i - 1][x]].l - a[i - 1]));
                    
                    f[i][j] = min(f[i][j], f[i - 1][k] + res);
                } else
                    f[i][j] = min(f[i][j], f[i - 1][k]);
            }
        }
    
    if (id[n].size()) 
        for (int i = 0; i < 2; i++)
            f[n][i] += (2 - i)*(b[id[n][id[n].size() - 1]].l - a[n]);
    
    printf("%lld\n", min(f[n][0], f[n][1]));
}

int main() {
    scanf("%d", &T);

    while (T--) {
        init_();
        work_();
    }
}