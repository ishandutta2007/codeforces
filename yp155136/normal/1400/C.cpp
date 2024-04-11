#include <bits/stdc++.h>
using namespace std;

void go() {
    string s; cin >> s; 
    int n = (int)s.size();
    s = " " + s;
    int x; cin >> x;
    string ans(n + 1, '2');
    for (int i = 1; i <= n; ++i) {
        bool flag = false;
        if (i > x) {
            if (s[i] == '1') {
                if (ans[i - x] == '0') {
                    flag = true;
                    /*cout << -1 << endl;
                      return;*/
                }
                else {
                    ans[i - x] = '1';
                    continue;
                }
            }
            else {
                if (ans[i - x] == '1') {
                    cout << -1 << endl;
                    return;
                } 
                ans[i - x] = '0';
            }
        }
        if (i + x <= n) {
            if (s[i] == '1') {
                if (ans[i + x] == '0') {
                    /*cout << -1 << endl;
                      return;*/
                    flag = true;
                }
                else {   
                    ans[i + x] = '1';
                    continue;
                }
            }
            else {
                if (ans[i + x] == '1') {
                    cout << -1 << endl;
                    return;
                }
                ans[i + x] = '0';
            }
        }
        if (flag) {
            cout << -1 << endl;
            return;
        }
        if (s[i] != '0') {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == '2') {
            ans[i] = '1';
        }
        cout << ans[i];
    }
    cout << endl;
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        go();
    }
}