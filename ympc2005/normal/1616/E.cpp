#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, T, t[N];

ll ans;

vector <int> p[35];

char a[N], b[N];

void upd_(int x, int k) {
    for (; x <= n; x += x&-x) {
        t[x] += k;
    }
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x) {
        res += t[x];
    }

    return res;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s%s", &n, a + 1, b + 1);

        for (int i = 0; i < 26; i++) {
            p[i].clear();
        }

        for (int i = 1; i <= n; i++) {
            t[i] = 0;
            p[a[i] - 'a'].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            reverse(p[i].begin(), p[i].end());
        }

        for (int i = 1; i <= n; i++) {
            upd_(i, 1);
        }

        ans = 1e18;

        ll sum = 0;

        for (int i = 1; i <= n; i++) {
            ll mn = 1e18;

            for (int j = 0; j < b[i] - 'a'; j++) {
                if (p[j].size()) {
                    mn = min(mn, ask_(p[j].back()) - 1ll);
                }
            }

            ans = min(ans, sum + mn);

            if (!p[b[i] - 'a'].size()) {
                break;
            }

            int x = p[b[i] - 'a'].back();
            p[b[i] - 'a'].pop_back();
            sum += ask_(x) - 1;
            upd_(x, -1);
        }

        printf("%lld\n", ans < 1e18 ? ans : -1);
    }
}