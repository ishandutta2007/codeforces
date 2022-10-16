#include <bits/stdc++.h>
using namespace std;
string s;
bool check(int k) {
    int one_count = 0;
    for (auto&& x : s) one_count += (x == '1');
    one_count -= (s[0] == '1');

    int zero_count = (s[0] == '0');
    for (int i = 0, j = 0; i < s.size(); i++) {
        while (j + 1 < s.size()) {
            if (s[j + 1] == '1') {
                one_count--;
                j++;
            } else if (zero_count < k) {
                zero_count++;
                j++;
            } else {
                break;
            }
        }
        if (one_count <= k) return true;
        if (s[i] == '0') zero_count--;
        else one_count++;
    }
    return false;
}
void solve() {
    cin >> s;
    int low = 0, high = s.size(), mid, res;
    while (low <= high) {
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}