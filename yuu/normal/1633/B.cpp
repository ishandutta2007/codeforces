#include <bits/stdc++.h>
using namespace std;
string s;
void solve() {
    int cnt_0 = 0, cnt_1 = 0;
    cin >> s;
    for (auto&& c : s) {
        if (c == '0')
            cnt_0++;
        else
            cnt_1++;
    }
    if (cnt_0 > cnt_1) swap(cnt_0, cnt_1);
    if (cnt_0 < cnt_1)
        cout << cnt_0 << '\n';
    else
        cout << cnt_0 - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}