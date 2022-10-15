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
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vi o(256);
    o['f'] = o['a'] = o['c'] = o['e'] = 1;
    int cnt = 0;
    for (int i = 0; i + 1 < n; ++i) for (int j = 0; j+1 < m; ++j) {
        vi t(256);
        t[v[i][j]]=t[v[i+1][j]]=t[v[i][j+1]]=t[v[i+1][j+1]] = 1;
        if (t == o) {
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}