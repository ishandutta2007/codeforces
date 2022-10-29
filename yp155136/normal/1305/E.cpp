#include <bits/stdc++.h>
using namespace std;

const int C = 1000000000;
const int MAGIC = 5000 * 10;

int main () {
    int n, m; cin >> n >> m;
    if (m == 0) {
        for (int i = 1; i <= n; ++i) {
            cout << C - 2 * n +  i << ' ';
        }
        cout << endl;
        exit(0);
    }
    int big = 0;
    for (int i = 1; i <= n; ++i) {
        if (i >= 3 && i % 2 == 1) {
            big += i / 2;
        }
        else if (i >= 3 && i % 2 == 0) {
            big += i / 2 - 1;
        }
    }
    if (big < m) cout << -1 << endl;
    else {
        vector<int> a;
        for (int i = 1; i <= n; ++i) {
            if (m == 0) {
                a.push_back(C - MAGIC * (n - i));
            }
            else if (i <= 2) {
                a.push_back(i);
            }
            else {
                int can = (i % 2 == 1 ? i / 2 : i / 2 - 1);
                if (can <= m) {
                    a.push_back(i);
                    m -= can;
                }
                else {
                    a.push_back((i - 1) + (i - 2 * m));
                    m = 0;
                }
            }
        }
        for (int i: a) cout << i << ' '; cout << endl;
    }
}