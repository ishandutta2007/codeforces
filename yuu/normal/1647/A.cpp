#include <bits/stdc++.h>
using namespace std;
int n;
string ans;
void solve() {
    cin >> n;
    ans = "";
    while (n >= 3) {
        ans += "2";
        ans += "1";
        n -= 3;
    }
    if (n == 1)
        ans = "1" + ans;
    else if (n == 2)
        ans += "2";
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}