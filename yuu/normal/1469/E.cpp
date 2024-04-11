#include <bits/stdc++.h>
using namespace std;
int n, k;
string s, t;
vector<int> req;
int make_bit(int i) {
    int ans = 0;
    for (int j = i + k - 1; j >= i; j--) (ans *= 2) += (s[j] - '0');
    return ans;
}
void solve() {
    cin >> n >> k;
    cin >> s;
    t = "";
    while (k > 20) {
        t.push_back('0');
        k--;
    }
    req.clear();
    for (int i = 0, last_zero = -1; i < n; i++) {
        if (i + k > n) break;
        if (i >= t.size()) {
            if (last_zero + static_cast<int>(t.size()) < i) {
                req.push_back(make_bit(i));
            }
        }
        if (s[i] == '0') last_zero = i;
    }
    sort(req.begin(), req.end());
    req.erase(unique(req.begin(), req.end()), req.end());
    if (req.size() >= (1 << k)) {
        cout << "NO\n";
        return;
    }
    while (k) {
        int count_one = 0;
        for (auto&& x : req) count_one += (x % 2);
        int chosen = !(count_one < (1 << (k - 1)));
        t.push_back(char(chosen + '0'));
        req.erase(partition(req.begin(), req.end(), [chosen](const int& x) { return (x % 2) != chosen; }), req.end());
        for (auto&& x : req) x /= 2;
        k--;
    }
    cout << "YES\n";
    cout << t << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}