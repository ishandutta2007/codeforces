#include <bits/stdc++.h>
using namespace std;

int T, n, a[200010];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), a[i] ^= a[i - 1];
        }
        if (a[n]) { puts("NO"); continue; }
        vector<int> V;
        auto print = [&](int l, int r) {
            for (int i = r - 2; i >= l; i -= 2) V.push_back(i);
            for (int i = l; i < r; i += 2) V.push_back(i);
        };
        if (n & 1) {
            print(1, n);
        } else {
            for (int i = 1; i <= n; i += 2) if (!a[i]) {
                print(1, i), print(i + 1, n); break;
            }
        }
        if (V.empty()) { puts("NO"); continue; }
        printf("YES\n%d\n", V.size());
        for (int x : V) printf("%d ", x);
        putchar('\n');
    }
    return 0;
}