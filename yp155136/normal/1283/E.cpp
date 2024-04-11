#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200010;

ll dp[N], cnt[N];
int a[N];
ll yuuki[N];

void ccopy() {
    for (int i = 0; i < N; ++i) {
        yuuki[i] = cnt[i];
    }
}

ll pre[N];

int main () {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[ a[i] ]++;
    }
    ccopy();
    int ans2 = 0;
    for (int i = 0; i <= n + 2; ++i) {
        if (i > 0 && yuuki[i - 1]) {
            --yuuki[i - 1];
            ++ans2;
        }
        else if (yuuki[i]) {
            --yuuki[i];
            ++ans2;
        }
        else if (yuuki[i + 1]) {
            --yuuki[i + 1];
            ++ans2;
        }
    }
    for (int i = 1; i <= n + 2; ++i) {
        pre[i] = pre[i - 1] + cnt[i];
    }
    for (int i = 1; i <= n + 2; ++i) {
        if (i == 1) {
            if (cnt[i]) dp[i] = 1;
            else dp[i] = 0;
        }
        else if (i == 2) {
            if (cnt[i] || cnt[i - 1]) {
                dp[i] = 1;
            }
            else {
                dp[i] = 0;
            }
        }
        else {
            dp[i] = min(dp[i - 2] + (pre[i] - pre[i - 2] > 0),
                        dp[i - 3] + (pre[i] - pre[i - 3] > 0));
            dp[i] = min(dp[i], dp[i - 1] + (pre[i] - pre[i - 1] > 0));
        }
    }
    cout << dp[n + 2] << ' ' << ans2 << endl;
}