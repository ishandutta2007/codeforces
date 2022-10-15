#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string str;
    cin >> n >> k >> str;
    sort(str.begin(), str.end(), greater());
    vector<int> cnt(26);
    for (char c : str) {
        cnt[c - 'a']++;
    }
    for (int t = 1; t <= k; t++) {
        for (int i = 0; i < 26; i++) {
            if (!cnt[i] || i == n / k) {
                cout.put('a' + i);
                for (int j = 0; j < i; j++) cnt[j]--;
                break;
            }
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}