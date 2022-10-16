#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[10];
string s[10];
int cnt[21];
vector<int> group[21];
int ans[10000];
int triangle[10001];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> s[i];
    int best = 0;
    int best_mark = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int j = 0; j <= 20; j++) cnt[j] = 0;
        for (int q = 0; q < m; q++) {
            int weight = 10;
            for (int i = 0; i < n; i++)
                if (s[i][q] == '1') {
                    if ((mask >> i) & 1)
                        weight--;
                    else
                        weight++;
                }
            cnt[weight]++;
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                res += x[i];
            else
                res -= x[i];

        int now = m;
        for (int i = 20; i >= 0; i--) {
            res += (triangle[now] - triangle[now - cnt[i]]) * (i - 10);
            now -= cnt[i];
        }
        assert(now == 0);
        if (res > best) {
            best = res;
            best_mark = mask;
        }
    }


    for (int mask = best_mark; mask <= best_mark; mask++) {
        for (int j = 0; j <= 20; j++) group[j].clear();
        for (int q = 0; q < m; q++) {
            int weight = 10;
            for (int i = 0; i < n; i++)
                if (s[i][q] == '1') {
                    if ((mask >> i) & 1)
                        weight--;
                    else
                        weight++;
                }
            group[weight].push_back(q);
        }
        int now = m;
        for (int i = 20; i >= 0; i--) {
            while (!group[i].empty()) {
                ans[group[i].back()] = now--;
                group[i].pop_back();
            }
        }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i + 1 == m];
}

int main() {
    for (int i = 1; i <= 10000; i++) triangle[i] = triangle[i - 1] + i;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}