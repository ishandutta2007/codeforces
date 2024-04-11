#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
    cin >> s;
    for (int i = s.size() - 2; i >= 0; i--) {
        int sum = (s[i] - 48) + (s[i + 1] - 48);
        if (sum >= 10) {
            s[i] = '1';
            s[i + 1] = sum % 10 + 48;
            cout << s << '\n';
            return;
        }
    }
    for (int i = 0; i + 1 < s.size(); i++) {
        int sum = (s[i] - 48) + (s[i + 1] - 48);
        if (sum > s[i] - 48) {
            s[i] = sum + 48;
            s.erase(i + 1, 1);
            cout << s <<'\n';
            return;
        }
    }
    s.pop_back();
    cout << s <<'\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}