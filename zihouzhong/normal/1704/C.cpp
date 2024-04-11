#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<int> len = {a[0] + n - a[m - 1] - 1};
        for (int i = 0; i < m - 1; i++) {
            len.push_back(a[i + 1] - a[i] - 1);
        }
        sort(len.begin(), len.end(), greater<>());
        int s = 0, cnt = 0;
        for (int x : len) {
            s += min(x, 2 * cnt), x -= 2 * cnt;
            if (x > 0) {
                x--, cnt++;
                if (x) {
                    s++;
                    if (x > 1) cnt++;
                }
            }
        }
        cout << s + m << "\n";
    }
    return 0;
}