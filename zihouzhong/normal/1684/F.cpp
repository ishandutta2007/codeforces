#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, m, a[maxn], l[maxn], r[maxn], mark[maxn], pos[maxn], mx[20][maxn];
int pre[maxn], nxt[maxn];
vector<int> Q[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), Q[i].clear();
        }
        fill(mx[0] + 1, mx[0] + n + 1, 0);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &l[i], &r[i]);
            mx[0][l[i]] = max(mx[0][l[i]], r[i]);
        }
        for (int i = 1; i < 20; i++) {
            for (int j = 1; j + (1 << i) - 1 <= n; j++) {
                mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
            }
        }
        auto qmax = [&](int l, int r) {
            int k = __lg(r - l + 1);
            return max(mx[k][l], mx[k][r - (1 << k) + 1]);
        };
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            pre[i] = mp[a[i]], mp[a[i]] = i;
        }
        for (int i = 1; i <= n; i++) {
            int j = qmax(pre[i] + 1, i);
            if (j <= i) pos[i] = 0;
            else Q[j].push_back(i);
        }
        mp.clear();
        for (int i = 1; i <= n; i++) {
            mp[a[i]] = i;
            for (int j : Q[i]) pos[j] = mp[a[j]];
        }
        mp.clear();
        for (int i = n; i; i--) {
            nxt[i] = mp[a[i]], mp[a[i]] = i;
        }
        auto chk = [&](int lim) {
            fill(mark + 1, mark + n + 1, 0);
            int lb = 1, rb = n - lim + 1;
            for (int i = 1; i <= n; i++) {
                int j = pos[i];
                if (j <= i) continue;
                lb = max(lb, pre[j] - lim + 1);
                rb = min(rb, nxt[i]);
                if (i < j - lim + 1) mark[i + 1]++, mark[j - lim + 1]--;
            }
            for (int i = 1; i <= n; i++) {
                mark[i] += mark[i - 1];
                if (i >= lb && i <= rb && !mark[i]) return 1;
            }
            return 0;
        };
        int l = 0, r = n, ans = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}