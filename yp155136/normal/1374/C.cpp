#include <bits/stdc++.h>
using namespace std;

void go() {
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int cnt = 0;
    for (char i: s) {
        if (i == '(') {
            ++cnt;
        }
        else {
            if (cnt == 0) {
                ++ans;
            }
            else {
                --cnt;
            }
        }
    }
    cout << ans << endl;
}

int main () {
    int T; cin >> T;
    while (T--) {
        go();
    }
}