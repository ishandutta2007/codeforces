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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int n, m;
vector<vi> was(1000, vi(1000));
int cnt[2];
int x[8] = {-2, -2, 2, 2, -1, -1, 1, 1};//, 0, 0, 5, -5};
int y[8] = {-1, 1, 1, -1, 2, -2, 2, -2};//, 5, -5, 0, 0};

bool in (int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void dfs (int i, int j, int col) {
    if (!was[i][j]) {
        was[i][j] = 1;
        ++cnt[col];
        for (int l = 0; l < 8; ++l) {
            int i1 = i + x[l], j1 = j + y[l];
            if (in(i1, j1))
                dfs(i1, j1, 1 - col);
        }
    }
}

int main() {
    cin >> n >> m;
    int res = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cnt[0] = cnt[1] = 0;
        dfs(i, j, 0);
        res += max(cnt[0], cnt[1]);
    }
    cout << res << endl;
    return 0;
}