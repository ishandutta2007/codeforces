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
    ll s = 0;
    ll x1 = 1e9, x2 = -1e9, y1 = 1e9, y2 = -1e9,x,y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        x1 = min(x1, x);
        y1 = min(y1, y);
        x2 = max(x2, x);
        y2 = max(y2, y);
        ll a = x, b = y;
        cin >> x >> y;
        x1 = min(x1, x);
        y1 = min(y1, y);
        x2 = max(x2, x);
        y2 = max(y2, y);
        s += abs(x-a) * abs(y-b);
    }
    if (s == abs(x2-x1) * abs(y2 - y1) && abs(x2-x1)==abs(y2-y1)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}