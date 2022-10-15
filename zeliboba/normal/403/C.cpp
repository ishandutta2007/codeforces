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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

vvi a;
vi was;
int c = 0;
void dfs(int v) {
    if (!was[v]) {
        ++c;
        was[v] = 1;
        for (int i = 0; i < a.size(); ++i) if (a[i][v]) {
            dfs(i);
        }
    }
}

void dfs1(int v) {
    if (!was[v]) {
        ++c;
        was[v] = 1;
        for (int i = 0; i < a.size(); ++i) if (a[v][i]) {
            dfs1(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
//    bool l = 1, r = 1;
    int b = 0;
    a.assign(n, vi(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        scanf("%d", &a[i][j]);
//        if (i < j && a[i][j]) l = 0;
//        if (i > j && a[i][j]) r = 0;
    }
    for (int i = 0; i < n; ++i) if (a[i][i])
        b = i;
    was.assign(n, 0);
    c = 0;
    dfs(b);
    if (c != n) {
        cout << "NO\n";
        return 0;
    }
    was.assign(n, 0);
    c = 0;
    dfs1(b);
    if (c != n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}