#include <bits/stdc++.h>
#define pdebug(x) cerr << __LINE__ << ": " << #x << " = " << x << '\n'
using namespace std;
int n;
string s;
void solve() {
    cin >> n >> s;
    string t = "";
    int ans = n;
    for (int a = 'a'; a <= 'z'; a++) {
        int i = 0, j = n - 1;
        int res = 0;
        while (i < j) {
            if (s[i] != a) {
                if (s[j] == a) {
                    j--;
                    res++;
                } else {
                    if (s[j] != s[i]) {
                        goto next_a;
                    } else {
                        i++;
                        j--;
                    }
                }
            } else {
                if (s[j] == a) {
                    i++;
                    j--;
                } else {
                    i++;
                    res++;
                }
            }
        }
        ans = min(ans, res);
    next_a:;
    }
    if (ans == n) ans = -1;
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}