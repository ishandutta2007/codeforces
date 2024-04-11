#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    char current = 'c';
    int size = 3;
    for (auto&& c : s) {
        if (c != current) {
            if (size < 2) {
                cout << "No\n";
                return;
            }
            current = c;
            size = 1;
        } else {
            size++;
        }
    }
    if (size < 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}