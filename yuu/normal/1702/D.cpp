#include <bits/stdc++.h>
using namespace std;
string w;
int p;
int cnt[256];
void solve() {
    cin >> w >> p;
    int cost = 0;
    for (auto&& x : w) {
        cnt[x]++;
        cost += x - 'a' + 1;
    }
    for (int i = 'z'; i >= 'a'; i--) {
        while (cnt[i] && (cost > p)) {
            cnt[i]--;
            cost -= i - 'a' + 1;
        }
    }
    for (auto&& x : w) {
        if (cnt[x] == 0) continue;
        cout << x;
        cnt[x]--;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}