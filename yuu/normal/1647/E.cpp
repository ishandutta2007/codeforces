#include <bits/stdc++.h>
using namespace std;
int n;
int p[100001];
vector<int> f[31];
int g[100001];
int a[100001];
bool filled[100001];
int added, highest_id, turn;
vector<int> possible_start[100001];
priority_queue<int, vector<int>, greater<int>> loser_spot;
int survived[100001];
int b[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        filled[p[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] <= n) survived[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        if (!filled[i]) added++;
    highest_id = *max_element(a + 1, a + n + 1);
    assert(added > 0);
    turn = (highest_id - n) / added;
    assert(highest_id == n + added * turn);
    f[0].resize(n + 1);
    for (int i = 1; i <= n; i++) f[0][i] = p[i];
    for (int i = 0; i < __lg(turn); i++) {
        f[i + 1].resize(n + 1);
        for (int u = 1; u <= n; u++) f[i + 1][u] = f[i][f[i][u]];
    }
    for (int i = 1; i <= n; i++) g[i] = i;
    for (int j = __lg(turn); j >= 0; j--) {
        if ((turn >> j) & 1) {
            for (int i = 1; i <= n; i++) g[i] = f[j][g[i]];
        }
        f[j].clear();
    }
    for (int i = 1; i <= n; i++) possible_start[g[i]].push_back(i);
    for (int i = 1; i <= n; i++) {
        if (survived[i]) {
            int best_pos = possible_start[survived[i]][0];
            b[best_pos] = i;
            for (auto&& x : possible_start[survived[i]])
                if (x != best_pos) loser_spot.push(x);
        } else {
            b[loser_spot.top()] = i;
            loser_spot.pop();
        }
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}