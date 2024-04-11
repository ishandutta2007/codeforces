#include <bits/stdc++.h>
using namespace std;
int zero, one, k;
void no() {
    cout << "No\n";
    exit(0);
}
void print(char c, int n) {
    for (int i = 1; i <= n; i++) cout << c;
}
void solve() {
    cin >> zero >> one >> k;
    if (k == 0) {
        cout << "Yes\n";
        print('1', one);
        print('0', zero);
        cout << '\n';

        print('1', one);
        print('0', zero);
        cout << '\n';
        return;
    }
    if ((one == 1) || (zero == 0)) no();
    // one >= 3 and zero >= 2
    if (k > one - 1 + zero - 1) no();
    cout << "Yes\n";
    string s = "1", t = "1";
    int n = one + zero - 1;
    one--;
    for (int i = 1; i <= n; i++) {
        if (n - i + 1 - 1 == k) {
            assert(one + zero > k);
            assert(one >= 1);
            assert(zero >= 1);
            for (int x = 1; x <= one; x++) s += '1';
            for (int y = 1; y <= zero; y++) s += '0';
            t += '0';
            for (int x = 1; x < one; x++) t += '1';
            for (int y = 1; y < zero; y++) t += '0';
            t += '1';
            cout << s << '\n' << t << '\n';
            return;
        } else {
            if (one > zero) {
                s += '1';
                t += '1';
                one--;
            } else {
                s += '0';
                t += '0';
                zero--;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}