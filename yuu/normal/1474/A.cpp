#include <bits/stdc++.h>
using namespace std;
int n;
string b;
string a;
void solve() {
    cin >> n >> b;
    a = b;
    char last = '?';
    for (int i = 0; i < n; i++) {
        if (last == '2') {
            a[i] = b[i] ^ '0' ^ '1';
            last = '1';
        } else if (b[i] == '1') {
            a[i] = '1';
            last = '2';
        } else if (last == '1') {
            a[i] = last = '0';
        } else {
            a[i] = '1';
            last = '1';
        }
    }
    cout << a << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}