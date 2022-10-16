#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int ans[200001];
int prev_flip[200001];
void solve() {
    cin >> n >> k >> s;
    if (k == 0) {
        cout << s << '\n';
        for (int i = 1; i <= n; i++) cout << 0 << " \n"[i == n];
        return;
    }
    s = 'a' + s;
    for (int i = 1; i <= n; i++) ans[i] = 0;
    for (int i = 1; i <= n; i++) prev_flip[i] = 0;
    if ("01"[k % 2] == s[1]) {
        ans[1] = 1;
        for (int i = 2; i <= n; i++) s[i] ^= ('0' ^ '1');
        k--;
    }
    for (int i = 2, flip = 0; i <= n; i++) {
        if (flip) s[i] ^= ('0' ^ '1');
        if (k && (s[i] != s[i - 1])) {
            prev_flip[i - 1] ^= 1;
            flip = !flip;
            ans[i] = 1;
            k--;
        }
    }
    for (int i = n - 1, flip = 0; i >= 1; i--) {
        flip ^= prev_flip[i];
        if (flip) s[i] ^= ('0' ^ '1');
    }
    if (k) {
        ans[n] += k;
        k %= 2;
    }
    if (k) {
        for (int i = 1; i < n; i++) s[i] ^= ('0' ^ '1');
    }
    cout << s.substr(1) << '\n';
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}