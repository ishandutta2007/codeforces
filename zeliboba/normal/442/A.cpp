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

int main() {
    int n;
    cin >> n;
    vs v(n);
    vii a(n);
    map<char, int> was1, was2;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (was1.count(v[i][0]) == 0) {
            int t = was1.size();
            was1[v[i][0]] = t;
        }
        if (was2.count(v[i][1]) == 0) {
            int t = was2.size();
            was2[v[i][1]] = t;
        }
        a[i] = pii(was1[v[i][0]], was2[v[i][1]]);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int M1 = (1 << was1.size()), M2 = (1 << was2.size());
    int res = was1.size() + was2.size();
    for (int mask1 = 0; mask1 < M1; ++mask1) for (int mask2 = 0; mask2 < M2; ++mask2) {
        int nres = 0;
        for (int i = 0; i < was1.size(); ++i) if ((1 << i) & mask1) {
            nres++;
        }
        for (int i = 0; i < was2.size(); ++i) if ((1 << i) & mask2) {
            nres++;
        }
        bool ok = 1;
        for (int i = 0; i < a.size(); ++i) {
            int cnt = 0;
            for (int j = 0; j < a.size(); ++j) {
                if (a[i].first != a[j].first) {
                    if (mask1 & (1 << a[i].first)) continue;
                    if (mask1 & (1 << a[j].first)) continue;
                }
                if (a[i].second != a[j].second) {
                    if (mask2 & (1 << a[i].second)) continue;
                    if (mask2 & (1 << a[j].second)) continue;
                }
                ++cnt;
            }
            if (cnt > 1) {
                ok = 0;
                break;
            }
        }
        if (ok) res = min(res, nres);
    }
    cout << res << endl;
    return 0;
}