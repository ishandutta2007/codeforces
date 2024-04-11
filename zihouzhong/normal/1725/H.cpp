#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
        x = (x % 3) * (x % 3) % 3;
    }
    int c0 = count(a.begin(), a.end(), 0);
    int c1 = count(a.begin(), a.end(), 1);
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j) {
        return a[i] % 3 < a[j] % 3;
    });
    if (c0 < c1) {
        cout << "0\n";
        string res(n, '0');
        for (int i = 0; i < n / 2; i++) {
            res[id[i]] = '1';
        }
        cout << res << "\n";
    } else {
        cout << "2\n";
        string res(n, '0');
        for (int i = 0; i < n / 2; i++) {
            res[id[i]] = '1';
        }
        cout << res << "\n";
    }
    return 0;
}