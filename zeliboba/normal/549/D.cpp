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

int main() {
    int n, m;
    cin >> n >> m;
    vs v(n);
    vvi t(n, vi(m, -1));
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        for (int j = 0; j < m; ++j) if (v[i][j] == 'W') t[i][j] = 1;
    }
    int res = 0;
    vvi s(n, vi(m));
    for (int i = n-1; i >= 0; --i) for (int j = m-1; j >= 0; --j) {
        if (s[i][j] != t[i][j]) ++res;
        s[i][j] = t[i][j];
        if (i) s[i-1][j] += s[i][j];
        if (j) s[i][j-1] += s[i][j];
        if (i && j) s[i-1][j-1] -= s[i][j];
    }
    cout << res << endl;
    return 0;
}