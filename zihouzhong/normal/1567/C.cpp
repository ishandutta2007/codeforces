#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        string n;
        cin >> n;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < n.size(); i += 2) s1 = s1 * 10 + n[i] - '0';
        for (int i = 1; i < n.size(); i += 2) s2 = s2 * 10 + n[i] - '0';
        if (!s2) cout << s1 - 1 << endl;
        else cout << 1LL * (s1 + 1) * (s2 + 1) - 2 << endl;
    }
    return 0;
}