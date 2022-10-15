#include <cstdio>
#include <cstdlib>
#include <cassert>
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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int n = 8;

bool in (int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < n;
}

int main() {
    int x[] = {1,-1,0,0,1,1,-1,-1,0};
    int y[] = {0,0,1,-1,1,-1,1,-1,0};
//    cin >> n;
    vector<string> vs(n);
    for (int i = 0; i < n; ++i)
        cin >> vs[i];
    vector<vvi> was(30, vvi(8, vi(8)));
    was[0][n-1][0] = 1;
    for (int t = 0; t + 1 < was.size(); ++t) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (was[t][i][j]) {
        if (i == 0 && j == n - 1) {
            cout << "WIN\n";
            return 0;
        }
        if (i < t || vs[i - t][j] != 'S') {
            for (int it = 0; it < 9; ++it) if (in(i+x[it], j+y[it]) && (i + x[it] < t || vs[i + x[it] - t][j + y[it]] != 'S')) {
                was[t + 1][i + x[it]][j + y[it]] = 1;
            }
        }
    }
    cout << "LOSE\n";
    return 0;
}