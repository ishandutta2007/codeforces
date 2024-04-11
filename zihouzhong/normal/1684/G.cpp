#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int n, m, t[maxn];
bool mark[maxn];
vector<array<int, 2>> ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    sort(t + 1, t + n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        mp[t[i]]++;
    }
    for (int i = n; i; i--) if (mp[t[i]]) {
        bool ok = 0;
        for (int j = n - 1; j; j--) if (2LL * t[i] + t[j] <= m) {
            vector<int> vec;
            int x = 2 * t[i] + t[j], y = t[i] + t[j];
            while (1) {
                if (x < y) swap(x, y);
                if (!y) break;
                int r = x % y;
                if (r) vec.push_back(r);
                x = r;
            }
            bool flag = 1;
            for (int x : vec) {
                if (!mp.count(x) || !mp[x]) { flag = 0; break; }
            }
            if (flag) {
                ans.push_back({2 * t[i] + t[j], t[i] + t[j]});
                for (int x : vec) mp[x]--;
                ok = 1; break;
            }
        }
        if (!ok && 3LL * t[i] <= m) {
            ans.push_back({3 * t[i], 2 * t[i]});
            mp[t[i]]--, ok = 1;
        }
        if (!ok) puts("-1"), exit(0);
    }
    printf("%d\n", ans.size());
    for (auto &p : ans) {
        printf("%d %d\n", p[0], p[1]);
    }
    return 0;
}