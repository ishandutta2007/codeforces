#include <bits/stdc++.h>
using namespace std;

int main () {
    int n; cin >> n;
    vector<int> v(n), a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[i] = i;
    }
    sort(v.begin(), v.end(), [a](const int &x, const int &y) {
        return a[x] > a[y];
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (a[  v[i] ] * i + 1);
    }
    cout << ans << endl;
    for (int i: v) cout << i + 1 << ' ';
    cout << endl;
}