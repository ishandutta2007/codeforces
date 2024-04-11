#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
    int n, m; scanf("%d%d", &n, &m);
    map<int, int> mp;
    queue<int> que;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        mp[x] = 0;
        que.push(x);
    }
    vector<int> anss;
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        if (mp[t] > 0) {
            anss.push_back(t);
            ans += mp[t];
            if (anss.size() == m) break;
        }
        for (int to: {t - 1, t + 1}) {
            if (mp.find(to) == mp.end()) {
                mp[to] = mp[t] + 1;
                que.push(to);
            }
        }
    }
    cout << ans << endl;
    for (int i: anss) cout << i << ' ';
}