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
    int n, m; cin >> n >> m;
    vi w(n), b(m);
    for (int i = 0; i < n; ++i) cin >> w[i];
    vi was(n);
    vi v;
    for (int i = 0; i < m; ++i) {
        cin >> b[i]; --b[i];
        if (!was[b[i]]) v.push_back(b[i]);
        was[b[i]] = 1;
    }
    for (int i = 0; i < n; ++i) if (!was[i])
        v.push_back(i);
    reverse(v.begin(), v.end());
    ll res = 0;
    for (int i = 0; i < b.size(); ++i) {
        int pos = 0;
        for (; pos < n && v[pos] != b[i]; ++pos) {}
        for (; pos + 1 < n; ++pos) {
            res += w[v[pos + 1]];
            swap(v[pos], v[pos + 1]);
        }
    }
    cout << res << endl;
    return 0;
}