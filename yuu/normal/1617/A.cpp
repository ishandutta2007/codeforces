#include <bits/stdc++.h>
using namespace std;
string s, t;
int cnt[256];
void solve() {
    cin >> s >> t;
    string ans = "";
    string perm = "abc";
    for (int i = 'a'; i <= 'z'; i++) cnt[i] = 0;

    for (auto&& c : s) cnt[c]++;
    do {
        if (perm == t) continue;
        string res;
        for (auto&& c : perm) {
            for (int i = 0; i < cnt[c]; i++) res += c;
        }
        if ((ans == "") || (res < ans)) ans = res;
    } while (next_permutation(perm.begin(), perm.end()));
    for (int i = 'd'; i <= 'z'; i++)
        for (int j = 0; j < cnt[i]; j++) ans += char(i);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}