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

int main() {
    int n;
    cin >> n;
    vvi v(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        v[i].resize(s);
        for (int j = 0; j < s; ++j) {
            cin >> v[i][j];
            sum += v[i][j];
        }
    }
    vi ts;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < v[i].size()/2; ++j) {
            res += v[i][j];
        }
        if (v[i].size() % 2) {
            ts.push_back(v[i][v[i].size() / 2]);
        }
    }
    sort(ts.rbegin(), ts.rend());
    for (int i = 0; i < ts.size(); i += 2)
        res += ts[i];
    cout << res << ' ' << sum-res << endl;
    return 0;
}