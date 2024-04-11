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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    vii v(1, pii(a[0], 1));
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] == a[i-1]) ++v.back().second;
        else v.push_back(pii(a[i], 1));
    }
    vl d(v.size());
    d[0] = v[0].first * (ll)v[0].second;
    for (int i = 1; i < d.size(); ++i) {
        d[i] = d[i-1];
        ll add = v[i].first*(ll)v[i].second;
        if (v[i].first > v[i-1].first + 1) {
            d[i] = d[i-1] + add;
        } else {
            d[i] = max(d[i], add);
            if (i >= 2) d[i] = max(d[i], d[i-2] + add);
        }
    }
    cout << d.back() << endl;
    return 0;
}