#include <bits/stdc++.h>
using namespace std;

int T;
string n;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        char mn = *min_element(n.begin(), n.end());
        if (n.size() == 2) {
            cout << n[1] << "\n";
        } else {
            cout << mn << "\n";
        }
    }
    return 0;
}