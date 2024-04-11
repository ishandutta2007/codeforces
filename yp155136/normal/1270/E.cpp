#include <bits/stdc++.h>
using namespace std;

const int N = 1006;

int x[N], y[N];

int main () {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
        x[i] += 1000000;
        y[i] += 1000000;
    }
    while (true) {
        vector<int> v[2][2];
        for (int i = 1; i <= n; ++i) {
            v[ x[i] % 2 ][ y[i] % 2 ].push_back(i);
        }
        if ( 1 <= v[0][0].size() + v[1][1].size() && v[0][0].size() + v[1][1].size() <= n - 1) {
            cout << v[0][0].size() + v[1][1].size() << endl;
            for (int i: v[0][0]) cout << i << ' ';
            for (int i: v[1][1]) cout << i << ' ';
            return 0;
        }
        int x1 = 0, x2 = 1, y1 = 0, y2 = 1;
        if (v[x1][y1].size() + v[x2][y2].size() == 0) {
            y1 = 1;
            y2 = 0;
        }
        if (1 <= v[x1][y1].size() && v[x1][y1].size() <= n - 1) {
            cout << v[x1][y1].size() << endl;
            for (int i: v[x1][y1]) cout << i << ' ';
            cout << endl;
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            x[i] >>= 1;
            y[i] >>= 1;
        }
    }
}