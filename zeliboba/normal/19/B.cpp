#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

long long mmin(long long x, long long y) {
    if (x == -1)
        return y;
    if (y == -1)
        return x;
    if (x < y)
        return x;
    else
        return y;
}

int main() {
    int n;
    cin >> n;
    vector<long long> t(n), c(n);
    for (int i = 0; i < n; ++i) cin >> t[i] >> c[i];
    vector<vector<long long> > b(3 * 2000 + 1, vector<long long>(n + 1, -1));
    b[n][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < b.size(); ++j) if (b[j][i] >= 0) {
            if (0 <= j - 1) {
                b[j - 1][i + 1] = mmin(b[j - 1][i + 1], b[j][i]);
            }
            if (j + t[i] < b.size()) {
                b[j + t[i]][i + 1] = mmin(b[j + t[i]][i + 1], b[j][i] + c[i]);
            }
        }
/*        for (int j = 0; j < b.size(); ++j)
            cout << b[j][i + 1] << '\t';
        cout << '\n';
        */
    }
    long long res = b[n][n];
    for (int i = n; i < b.size(); ++i)
        res = mmin(res, b[i][n]);
    cout << res << endl;
    return 0;
}