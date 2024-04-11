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
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;

int main() {
    int MAX = 2e9;
    int n;
    cin >> n;
    vi a(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vi> res(n, vi(n, MAX));
    vector<vector<pii> > path(n, vii(n));
    vector<vector<pii> > out(n, vii(n));
    for (int i = 0; i < n; ++i) {
        res[0][i] = a[i];
        path[0][i] = pii(-1, -1);
        out[0][i] = pii(i + 1, 0);
    }
    for (int i = 0; i < n - 1; ++i) {
        res[1][i] = max(a[i], a.back());
        path[1][i] = pii(-1, -1);
        out[1][i] = pii(i + 1, n);
    }
    for (int tail = 2; tail < n; ++tail) {
        for (int first = 0; first < n - tail; ++first) {
            int add = max(a[n - tail + 1], a[n - tail]);
            if (res[tail][first] > res[tail - 2][first] + add) {
                res[tail][first] = res[tail - 2][first] + add;
                path[tail][first] = pii(tail - 2, first);
                out[tail][first] = pii(n - tail + 2, n - tail + 1);
            }
//            printf("%d %d = %d %d %d\n", tail, first, res[tail][first], add, res[tail - 2][first]);
            add = max(a[n - tail + 1], a[first]);
            if (res[tail][first] > res[tail - 2][n - tail] + add) {
                res[tail][first] = res[tail - 2][n - tail] + add;
                path[tail][first] = pii(tail - 2, n - tail);
                out[tail][first] = pii(n - tail + 2, first + 1);
            }
//            printf("%d %d = %d\n", tail, first, res[tail][first]);
            add = max(a[n - tail], a[first]);
            if (res[tail][first] > res[tail - 2][n - tail + 1] + add) {
                res[tail][first] = res[tail - 2][n - tail + 1] + add;
                path[tail][first] = pii(tail - 2, n - tail + 1);
                out[tail][first] = pii(n - tail + 1, first + 1);
            }
//            printf("%d %d = %d\n", tail, first, res[tail][first]);
        }
//        printf("\n");
    }
    pii cur(n - 1, 0);
    printf("%d\n", res[n - 1][0]);
    while (cur != pii(-1, -1)) {
        if (cur.first)
            printf("%d %d\n", out[cur.first][cur.second].first, out[cur.first][cur.second].second);
        else
            printf("%d\n", out[0][cur.second].first);
        cur = path[cur.first][cur.second];
    }
    return 0;
}