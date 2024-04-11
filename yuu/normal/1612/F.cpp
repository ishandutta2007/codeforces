#include <bits/stdc++.h>
using namespace std;
int n, m, q;
bool trans;
int f[200001];
vector<int> syn[200001];
vector<pair<int, int>> update;
void solve() {
    // Easy to see that at any point, we should use our best weapon and armor.
    //    Even if we were to have synergy, we are still sacifising at least 1 power to not using them.
    // Thus we only need to care about the best armor and weapon we have
    // -> DP f[i] is what is the best armor we can have if the best weapon we have is x
    // One major setback is that n can be much less than m, so the amount of turn might be as big as m/n
    // We claim that after a logarithmic amount of turn on min(m, n), we can use the straight forward way to get to the answer.
    cin >> n >> m >> q;
    if (n > m) {
        swap(n, m);
        trans = true;
    }
    for (int i = 1, a, b; i <= q; i++) {
        cin >> a >> b;
        if (trans) swap(a, b);
        syn[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        sort(syn[i].begin(), syn[i].end());
        reverse(syn[i].begin(), syn[i].end());
    }
    for (int i = 1; i <= 200000; i++) f[i] = -1e9;
    f[1] = 1;
    constexpr int pre = 50;
    for (int turn = 1; turn <= pre; turn++) {
        update.clear();
        for (int i = n; i >= 1; i--) {
            if (f[i] <= 0) continue;
            while ((!syn[i].empty()) && (syn[i].back() < f[i])) syn[i].pop_back();
            int reach = i + f[i];
            if ((!syn[i].empty()) && (f[i] == syn[i].back())) reach++;
            update.emplace_back(i, min(reach, m));
            update.emplace_back(min(reach, n), f[i]);
        }
        for (auto&& [i, val] : update) f[i] = max(f[i], val);

        if (f[n] == m) {
            cout << turn << '\n';
            return;
        }
    }
    // not done
    int ans = pre;
    while (f[n] != m) {
        ans++;
        while ((!syn[n].empty()) && (syn[n].back() < f[n])) syn[n].pop_back();
        int reach = n + f[n];
        if ((!syn[n].empty()) && (f[n] == syn[n].back())) reach++;
        f[n] = min(m, reach);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}