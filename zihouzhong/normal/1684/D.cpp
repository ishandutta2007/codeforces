#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, k, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        long long sum = 0;
        vector<int> V;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), sum += a[i];
            V.push_back(n - i - a[i]);
        }
        sort(V.begin(), V.end());
        long long ans = sum;
        for (int i = 0; i < V.size() && i < k; i++) {
            sum += V[i];
            ans = min(ans, sum - 1LL * i * (i + 1) / 2);
        }
        printf("%lld\n", ans);
    }
    return 0;
}