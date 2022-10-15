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
    vi h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    int l = 0, r = n;
    vii v(n + 2);
    while (r - l > 1) {
        int x = (l + r) / 2;
        for (int i = 0; i < n; ++i) {
            if (h[i] <= x) {
                int d = x - h[i];
                v[i] = pii(i - d, i + d);
//                cerr << x << ' ' << i - d << ' ' << i + d << endl;
            } else {
                v[i] = pii(n, n);
            }
        }
        v[n] = pii(0, x - 1);
        v[n+1] = pii(n - x, n-1);
        sort(v.begin(), v.end());
        int ma = v[0].second;
        bool ok = 1;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i].first <= ma + 1) {
                ma = max(ma, v[i].second);
            } else {
                ok = 0;
                break;
            }
        }
        if (ok) {
            r = x;
        } else {
            l = x;
        }
    }
    cout << r << endl;
    return 0;
}