#include <bits/stdc++.h>
using namespace std;
vector<int> pos[4];
int cnt[4];
int id[256];
int64_t f[4][4];
string a;
void make(int i, int j) {
    if (i == j) return;
    f[i][j] = 0;
    auto &a = pos[i];
    auto &b = pos[j];
    // place i before j
    int y = 0;
    for (int x = 0; x < a.size(); x++) {
        while ((y < b.size()) && (b[y] < a[x])) y++;
        f[i][j] += y;
    }
}
int order[4];
int best_order[4];
void solve() {
    for (int i = 0; i < 4; i++) pos[i].clear();
    cin >> a;
    {
        int i = 0;
        for (auto &&c : a) pos[id[c]].push_back(i++);
    }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) make(i, j);

    int64_t ans = -1e9;
    for (int i = 0; i < 4; i++) order[i] = i;
    for (int i = 0; i < 4; i++) best_order[i] = i;
    do {
        int64_t res = 0;
        for (int i = 0; i < 4; i++)
            for (int j = i + 1; j < 4; j++) res += f[order[i]][order[j]];

        if (res > ans) {
            ans = res;
            for (int i = 0; i < 4; i++) best_order[i] = order[i];
        }
    } while (next_permutation(order, order + 4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < pos[best_order[i]].size(); j++) {
            cout << "ANOT"[best_order[i]];
        }
    }
    cout << '\n';
}

int main() {
    for (int i = 0; i < 4; i++) id["ANOT"[i]] = i;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}