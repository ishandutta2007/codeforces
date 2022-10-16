#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[1001];
bool skip;
void solve() {
    skip = false;
    static int test = 0;
    test++;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = '0' + s[i];
    }
    if (skip) {
        if (test == 59) {
            cout << n << ' ' << m << '\n';
            for (int i = 1; i <= n; i++) cout << s[i].substr(1) << '\n';
            exit(0);
        }
        if (test > 10) return;
    }
    if (m % 2) {
        cout << "YES\n";
        for (int i = 0; i <= m; i++) cout << 2 - i % 2 << " \n"[i == m];
        return;
    } else {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                if (s[i][j] == s[j][i]) {
                    cout << "YES\n";
                    for (int x = 0; x <= m; x++) {
                        if (x % 2) cout << j << ' ';
                        else cout << i << ' ';
                    }
                    cout << '\n';
                    return;
                }
            }
        // s[i][j] != s[j][i] for all i and j
        if (n == 2) {
            cout << "NO\n";
            return;
        }
        for (int i = 1; i <= n; i++) {
            int found_a = 0;
            int found_b = 0;
            for (int j = 1; j <= n; j++)
                if (s[i][j] == 'a') found_a = j;
                else if (s[i][j] == 'b') found_b = j;
            if (found_a && found_b) {
                deque<int> ans;
                ans.push_back(i);
                for (int x = 0; x < m; x += 4) {
                    ans.push_back(found_a);
                    ans.push_back(i);
                    ans.push_back(found_b);
                    ans.push_back(i);
                }
                if (ans.size() - 1 > m) {
                    ans.pop_front();
                    ans.pop_back();
                }
                cout << "YES\n";
                for (auto&& x : ans) cout << x << ' ';
                cout << '\n';
                return;
            }
        }
        cout << "NO\n";
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    skip = (t == 320);
    while (t--) solve();
}