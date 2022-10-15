#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

char v[51][51];
char res[101][101];

int main() {
    int n;
    scanf("%d", &n);
    vvi was(n, vi(n));
    for (int i = 0; i < n; ++i) scanf("%s", v[i]);
    for (int i = 0; i < 2*n-1; ++i) for (int j = 0; j < 2*n-1; ++j) res[i][j] = '.';
    res[n-1][n-1] = 'o';
    for (int i = 0; i < 2*n-1; ++i) for (int j = 0; j < 2*n-1; ++j) if (res[i][j] == '.') {
        int dx = i - n + 1, dy = j - n + 1;
        res[i][j] = 'x';
        for (int x = 0; x < n && res[i][j] == 'x'; ++x) for (int y = 0; y < n; ++y) if (v[x][y] == 'o') {
            int x1 = x + dx, y1 = y + dy;
            if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < n && v[x1][y1] == '.') {
                res[i][j] = '.';
                break;
            }
        }
        if (res[i][j] == 'x') {
            for (int x = 0; x < n; ++x) for (int y = 0; y < n; ++y) if (v[x][y] == 'o') {
                int x1 = x + dx, y1 = y + dy;
                if (x1 >= 0 && y1 >= 0 && x1 < n && y1 < n) {
                    was[x1][y1] = 1;
                }
            }
        }
    }
    bool fail = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (v[i][j] == 'x' && !was[i][j]) {
        fail = 1;
        break;
    }
    if (fail) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < 2*n-1; ++i) {
            for (int j = 0; j < 2*n-1; ++j) {
                printf("%c", res[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}