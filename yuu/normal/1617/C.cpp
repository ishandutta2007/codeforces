#include <bits/stdc++.h>
using namespace std;
int n;
int cnt[200001];
deque<int> big;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    big.clear();
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a <= n)
            cnt[a]++;
        else
            big.push_back(a);
    }
    sort(big.begin(), big.end());
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        if (cnt[i]) {
            for (int j = 1; j < cnt[i]; j++) big.push_front(i);
        } else {
            if ((big.empty()) || (big.back() <= i * 2)) {
                cout << "-1\n";
                return;
            } else {
                big.pop_back();
                ans++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}