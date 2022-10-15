#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, k, a[maxn], res[maxn];
map<int, int> mp, occ;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        mp.clear(), occ.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), mp[a[i]]++;
        }
        for (auto &p : mp) {
            occ[p.second]++;
        }
        int ans = INT_MAX, cnt = 0;
        for (int mex = 0; mex <= n && cnt <= k; mex++) {
            int diff = mp.size() + cnt, rem = k;
            for (auto &p : occ) {
                int t = min(p.second, rem / p.first);
                diff -= t, rem -= t * p.first;
            }
            ans = min(ans, diff - mex);
            if (!mp.count(mex)) cnt++;
            else occ[mp[mex]]--;
        }
        printf("%d\n", ans);
    }
    return 0;
}