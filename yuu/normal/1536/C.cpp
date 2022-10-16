#include <bits/stdc++.h>
using namespace std;
int n;
string s;
map<pair<int, int>, int> ans;
void solve() {
    int d = 0, k = 0;
    cin >> n >> s;
    ans.clear();
    for (auto&& c : s) {
        if (c == 'D')
            d++;
        else
            k++;
        int dd = d, kk = k;
        int g = gcd(d, k);
        dd /= g;
        kk /= g;
        cout << ++ans[{dd, kk}] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}