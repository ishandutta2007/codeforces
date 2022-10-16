#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int cnt[256];
void solve() {
    cin >> n >> k >> s;
    if (n % k) {
        cout << "-1\n";
        return;
    }
    for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
    for (auto&& x : s) cnt[x]++;
    for (int i = 'a'; i <= 'z'; i++)
        if (cnt[i] % k) goto greater;
    cout << s << '\n';
    return;
greater:;
    string res = "";
    for (int i = n - 1; i >= 0; i--) {
        cnt[s[i]]--;
        if (s[i] == 'z') continue;
        int total = 0;
        int mx = 0;
        for (int c = 'a'; c <= 'z'; c++) {
            if (cnt[c] % k) {
                mx = c;
                total += k - cnt[c] % k;
            }
        }
        if (total + i > n) continue;
        if (total + i == n) {
            if (mx <= s[i]) continue;
            if (i) res = s.substr(0, i);
            for (int j = s[i] + 1; j <= 'z'; j++)
                if (cnt[j] % k) {
                    res += char(j);
                    break;
                }
            break;
        } else {
            if (i) res = s.substr(0, i);
            res += char(s[i] + 1);
            break;
        }
    }
    for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;
    for (auto&& x : res) cnt[x]++;
    int rem = n - res.size();

    for (int i = 'a'; i <= 'z'; i++)
        if (cnt[i] % k) {
            cnt[i] = k - cnt[i] % k;
            rem -= cnt[i];
        } else {
            cnt[i] = 0;
        }
    assert(rem >= 0);
    cnt['a'] += rem;
    for (int i = 'a'; i <= 'z'; i++)
        for (int j = 0; j < cnt[i]; j++) res += char(i);
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}