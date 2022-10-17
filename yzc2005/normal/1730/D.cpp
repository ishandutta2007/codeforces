#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    map<pair<char, char>, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[minmax(t[i], s[n - 1 - i])] += 1;
    }

    bool flag = false;
    for (auto it : mp) {
        if (it.second & 1) {
            if (it.first.first != it.first.second || flag) {
                cout << "NO\n";
                return;
            }
            flag = true;
        }
    }

    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
}