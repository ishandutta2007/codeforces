#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> p(n);
    for (int &x : p) {
        cin >> x;
    }
    sort(p.begin(), p.end(), greater());
    int ans = 0;
    for (int i = 0, r = n; i < r; i++) {
        int sum = p[i];
        while (r > i + 1 && sum <= d) sum += p[i], r--;
        if (sum <= d) continue;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}