#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        int cnt[2] = {0, 0};
        for (char c: s) {
            cnt[ c - '0' ]++;
        }
        if (min(cnt[0], cnt[1]) & 1) puts("DA");
        else puts("NET");
    }
}