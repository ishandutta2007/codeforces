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
    int n;
    cin >> n;
    vs v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    vi x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    vi a(n);
    for (int t = 0; t < n; ++t) {
        for (int i = 0; i < n; ++i) if (!a[i] && x[i] == 0) {
            a[i] = 1;
            for (int j = 0; j < n; ++j) x[j] -= (v[i][j] - '0');
        }
    }
    vi ans;
    for (int i = 0; i < n; ++i) if (a[i]) ans.push_back(i+1);
    cout << ans.size() << endl;
    for (auto i : ans) cout << i << ' ';
    return 0;
}