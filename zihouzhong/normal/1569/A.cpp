#include <bits/stdc++.h>
using namespace std;

int T, n;

int main() {
    cin >> T;
    while (T--) {
        string s;
        cin >> n >> s;
        int l = -1, r = -1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i, cur = 0; j < s.size(); j++) {
                if (s[j] == 'a') cur++;
                else cur--;
                if (!cur) l = i + 1, r = j + 1;
            }
        }
        cout << l << " " << r << '\n';
    }
    return 0;
}