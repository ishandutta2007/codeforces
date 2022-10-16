#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int c[200001][2];
void solve() {
    cin >> s;
    n = s.size();
    s = '0' + s;
    for (int i = 1; i <= n; i++) {
        c[i][0] = c[i - 1][0];
        c[i][1] = c[i - 1][1];
        if (s[i] != '?') c[i][s[i] == "01"[i % 2]]++;
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        int low = i + 1, high = n, mid, res = i;
        while (low <= high) {
            mid = (low + high) / 2;
            if ((c[mid][0] - c[i - 1][0] == 0) || (c[mid][1] - c[i - 1][1] == 0)) {
                res = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        ans += res - i + 1;
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