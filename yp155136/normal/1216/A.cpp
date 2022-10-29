#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    string s; cin >> s;
    string t = "";
    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        char a = s[2 * i], b = s[2 * i + 1];
        if (a != b) {
            t.push_back(a);
            t.push_back(b);
        }
        else {
            a = 'b' - a + 'a';
            t.push_back(a);
            t.push_back(b);
            ++ans;
        }
    }
    cout << ans << endl << t << endl;
}