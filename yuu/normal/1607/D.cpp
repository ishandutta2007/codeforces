#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int n;
int a[200000];
string s;
multiset<int> red, blue;
void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> s;
    red.clear();
    blue.clear();
    for (int i = 0; i < n; i++)
        if (s[i] == 'R')
            red.insert(a[i]);
        else
            blue.insert(a[i]);
    // red can only increase, blue can only decrease
    // if some blue can do n then it can also do i < n
    // so let red do largest value and blue fill the part
    for (int i = n; i >= 1; i--) {
        if (red.empty()) {
            if (*blue.rbegin() < i) {
                cout << "No\n";
                return;
            }
            blue.erase(blue.find(*blue.rbegin()));
        } else {
            if (*red.rbegin() > i) {
                cout << "No\n";
                return;
            }
            red.erase(red.find(*red.rbegin()));
        }
    }
    cout << "Yes\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}