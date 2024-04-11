#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() {
    cin >> n >> s;
    for (char ans = 'a'; ans <= 'z'; ans++)
        if (s.find(ans) == -1) {
            cout << ans << '\n';
            return;
        }
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            string ans = "";
            ans += a;
            ans += b;
            if (s.find(ans) == -1) {
                cout << ans << '\n';
                return;
            }
        }
    }
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            for (char c = 'a'; c <= 'z'; c++) {
                string ans = "";
                ans += a;
                ans += b;
                ans += c;
                if (s.find(ans) == -1) {
                    cout << ans << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}