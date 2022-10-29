#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b, c; cin >> a >> b >> c;
    int ans = 0;
    for (int x = 0; x <= c; ++x) {
        if (x <= a && c - x <= b) ++ans;
    }
    cout << ans << endl;
}