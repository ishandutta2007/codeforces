#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int T, n, a[N], b[N], p[N], cnt;

bool vis[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        cnt = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            vis[i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            p[a[i]] = b[i];
        }

        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                int sz = 0;

                for (int j = i; !vis[j]; j = p[j]) {
                    vis[j] = 1;
                    sz++;
                }

                cnt += sz/2;
            }
        }

        printf("%lld\n", 1ll*(n + n - cnt + 1)*cnt - 1ll*(cnt + 1)*cnt);
    }
}