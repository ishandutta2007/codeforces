#include <bits/stdc++.h>
using namespace std;

int T, n, a[2100];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool flag = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), flag |= (a[i] ^ i) & 1;
        }
        if (flag) { puts("-1"); continue; }
        int l = n;
        vector<int> ans;
        auto op = [&](int x) {
            ans.push_back(x);
            reverse(a + 1, a + x + 1);
        };
        while (l > 1) {
            while (l > 1 && a[l] == l && a[l - 1] == l - 1) l -= 2;
            if (l == 1) continue;
            int x;
            for (int i = 1; i <= l; i++) if (a[i] == l) x = i;
            op(x);
            for (int i = 1; i <= l; i++) if (a[i] == l - 1) x = i - 1;
            op(x), op(x + 2), op(3);
            op(l), l -= 2;
        }
        printf("%d\n", ans.size());
        for (int x : ans) printf("%d ", x);
        putchar('\n');
    }
    return 0;
}