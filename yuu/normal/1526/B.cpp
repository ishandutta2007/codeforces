#include <bits/stdc++.h>
using namespace std;
bool good[2001];
int x;
void solve() {
    cin >> x;
    if (x > 2000)
        cout << "YES\n";
    else if (good[x])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    good[0] = 1;
    for (int i = 1; i <= 2000; i++) {
        if ((!good[i]) && (i >= 11)) good[i] = good[i - 11];
        if ((!good[i]) && (i >= 111)) good[i] = good[i - 111];
        if ((!good[i]) && (i >= 1111)) good[i] = good[i - 1111];
    }
    int t = 1;
    cin >> t;
    while (t--) solve();
}