#include <bits/stdc++.h>

using namespace std;

const int inf = int(1e9) + int(1e5);

int qw[111];
int a[11][11];
int n;

int main() {
    cin >> n;
    iota(qw, qw + n, 0);
    for_each(qw, qw + n, [&] (int i) {
        for_each(qw, qw + n, [&] (int j) {
            cin >> a[i][j];
        });
    });
    for_each(qw, qw + n, [&] (int k) {
        for_each(qw, qw + n, [&] (int i) {
            for_each(qw, qw + n, [&] (int j) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            });
        });
    });
    int res = 0;
    for_each(qw, qw + n, [&] (int i) {
        for_each(qw, qw + n, [&] (int j) {
            res = max(res, a[i][j]);
        });
    });
    cout << res << '\n';
}