#include <bits/stdc++.h>
using namespace std;
int n;
int p[100001];
int mx[100001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    mx[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (p[i] > p[mx[i - 1]]) mx[i] = i;
        else mx[i] = mx[i - 1];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = mx[i]; j <= i; j++) cout << p[j] << ' ';
        i = mx[i];
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}