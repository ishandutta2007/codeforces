#include <bits/stdc++.h>
using namespace std;

int cnt[2];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    for (char c: s) {
        if (c == '(') cnt[0]++;
        else cnt[1]++;
    }
    if (cnt[0] == cnt[1]) {
        int pre = 0;
        int mn = 0;
        for (char i: s) {
            if (i == '(') ++pre;
            else --pre;
            mn = min(mn, pre);
        }
        if (mn >= -1) puts("Yes");
        else puts("No");
    }
    else {
        puts("No");
    }
}