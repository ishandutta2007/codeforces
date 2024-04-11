#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[300001];
char c[300001];
int ans[300001];
vector<int> pos[2];
deque<int> s;
int GetExplode(int i, int j) {
    if (x[i] > x[j]) swap(i, j);
    if ((c[i] == 'R') && (c[j] == 'L')) {
        return (x[j] - x[i]) / 2;
    } else if ((c[i] == 'L') && (c[j] == 'L')) {
        int moved = x[i];
        x[j] -= x[i];
        x[i] = 0;
        c[i] = 'R';
        return moved + GetExplode(i, j);
    } else if ((c[i] == 'R') && (c[j] == 'R')) {
        int moved = m - x[j];
        x[i] += moved;
        x[j] = m;
        c[j] = 'L';
        return moved + GetExplode(i, j);
    } else {
        int moved = min(x[i], m - x[j]);
        x[i] -= moved;
        x[j] += moved;
        if (x[i] == 0) c[i] = 'R';
        if (x[j] == m) c[j] = 'L';
        return moved + GetExplode(i, j);
    }
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    pos[0].clear();
    pos[1].clear();
    for (int i = 1; i <= n; i++) pos[x[i] % 2].push_back(i);
    for (int i = 1; i <= n; i++) ans[i] = -1;
    for (int mod = 0; mod < 2; mod++) {
        sort(pos[mod].begin(), pos[mod].end(), [](const int &a, const int &b) { return x[a] < x[b]; });
        s.clear();
        for (auto &&i : pos[mod]) {
            if (s.empty() || (c[i] == c[s.back()]) || (c[i] == 'R')) {
                s.push_back(i);
            } else {
                int j = s.back();
                s.pop_back();
                ans[i] = ans[j] = GetExplode(j, i);
            }
        }
        while (s.size() >= 2) {
            if ((c[s[0]] == 'L') && (c[s[1]] == 'L')) {
                int i = s.front();
                s.pop_front();
                int j = s.front();
                s.pop_front();
                ans[i] = ans[j] = GetExplode(i, j);
            } else {
                int i = s.back();
                s.pop_back();
                int j = s.back();
                s.pop_back();
                ans[i] = ans[j] = GetExplode(i, j);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}