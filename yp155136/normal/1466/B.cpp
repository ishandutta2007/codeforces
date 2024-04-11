#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int cnt[N];

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        for (int i = 0; i <= 2 * n + 2; ++i) cnt[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            cnt[x]++;
        }
        int ans = 0;
        for (int i = 1; i <= 2 * n + 2; ++i) {
            if (i && cnt[i - 1]) {
                ++ans;
                --cnt[i - 1];
            }
            else if (cnt[i]) {
                ++ans;
                --cnt[i];
            }
        }
        printf("%d\n", ans);
    }
}