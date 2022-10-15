#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, m, a[maxn];
long long ans;
map<long long, long long> mp;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> X = {(int)-1e9, (int)2e9};
    while (m--) {
        int x;
        scanf("%d", &x), X.push_back(x);
    }
    sort(X.begin(), X.end());
    for (int i = 0, j = 1, k = 1; i + 1 < X.size(); i++) {
        while (j <= n && 100 * (j - 1) <= X[i]) j++;
        while (k <= n && 100 * (k - 1) < X[i + 1]) k++;
        mp.clear();
        for (int p = j; p < k; p++) {
            if (100 * (p - 1) - X[i] <= X[i + 1] - 100 * (p - 1)) {
                mp[4LL * X[i] + 1] += a[p];
                mp[800 * (p - 1) - 4LL * X[i]] -= a[p];
            } else {
                mp[800 * (p - 1) - 4LL * X[i + 1] + 1] += a[p];
                mp[4LL * X[i + 1]] -= a[p];
            }
        }
        long long cur = 0;
        for (auto &p : mp) {
            ans = max(ans, cur += p.second);
        }
    }
    printf("%lld\n", ans);
    return 0;
}