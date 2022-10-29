#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m; cin >> n >> m;
    vector<string> a, b, c;
    while (n--) {
        string s; cin >> s;
        a.push_back(s);
    }
    while (m--) {
        string s; cin >> s;
        b.push_back(s);
    }
    int i = 0, j = 0;
    n = a.size(), m = b.size();
    while (true) {
        c.push_back(a[i % n] + b[j % m]);
        i++;
        j++;
        if (i % n == 0 && j % m == 0) break;
    }
    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        --x;
        x %= (int)c.size();
        cout << c[x] << endl;
    }
}