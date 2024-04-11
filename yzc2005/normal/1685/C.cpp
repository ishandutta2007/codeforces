#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, sum[N];
char s[N];
void solve() {
    cin >> n >> (s + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        sum[i] = sum[i - 1] + (s[i] == '(' ? 1 : -1);
    }
    if (*min_element(sum, sum + 2 * n + 1) >= 0) {
        cout << "0\n";
        return;
    }
    int pos = max_element(sum, sum + 2 * n + 1) - sum;
    int pos1 = 0, pos2 = 2 * n;
    while (sum[pos1 + 1] >= 0) {
        ++pos1;
    }
    while (sum[pos2 - 1] >= 0) {
        --pos2;
    }
    pos1 = max_element(sum, sum + pos1 + 1) - sum;
    pos2 = max_element(sum + pos2, sum + 2 * n + 1) - sum;
    if (sum[pos1] + sum[pos2] >= sum[pos]) {
        cout << "1\n";
        cout << pos1 + 1 << " " << pos2 << "\n";
    } else {
        cout << "2\n";
        cout << pos1 + 1 << " " << pos << "\n";
        cout << pos + 1 << " " << pos2 << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}