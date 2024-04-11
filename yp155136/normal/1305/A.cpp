#include <bits/stdc++.h>
using namespace std;

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        vector<int> a, b;
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            a.push_back(x);
        }
        for (int i = 1; i <= n; ++i) {
            int x; scanf("%d", &x);
            b.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i: a) cout << i << ' '; cout << endl;
        for (int i: b) cout << i << ' '; cout << endl;
    }
}