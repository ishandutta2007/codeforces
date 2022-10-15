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
    vi v(2*n-1);
    for (int i = 0; i < v.size(); ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i + 1 < v.size(); i += 2) {
        if (v[i] < 0) {
            v[i] *= -1;
            v[i+1] *= -1;
        } else break;
    }
    sort(v.begin(), v.end());
    if (n & 1) {
        v[0] = abs(v[0]);
    } else {
        if (v[0] < 0 && abs(v[0]) > abs(v[1])) {
            v[0] *= -1;
            v[1] *= -1;
        }
    }
    ll res = 0;
    for (int i = 0; i < v.size(); ++i)
        res += v[i];
    cout << res << endl;
    return 0;
}