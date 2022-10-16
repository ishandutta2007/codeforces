#include <bits/stdc++.h>
using namespace std;
int n, k;
string a, b;
int cnt[256];
int target[256];
void solve() {
    cin >> n >> k;
    for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
    for (int i = 'a'; i <= 'z'; i++) target[i] = 0;
    cin >> a >> b;
    for (auto&& x : a) cnt[x]++;
    for (auto&& x : b) target[x]++;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt[i] < target[i]) {
            cout << "NO\n";
            return;
        }
        int change = cnt[i] - target[i];
        if (change % k) {
            cout << "NO\n";
            return;
        }
        cnt[i + 1] += change;
    }
    cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}