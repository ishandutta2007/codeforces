#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

bool eq(pii x, pii y) {
    return x.first * y.second == x.second * y.first;
}

bool les(pii x, pii y) {
    return x.first * y.second < x.second * y.first;
}

int main() {
    ll t1,t2,x1,x2,t0;
    cin >> t1>>t2>>x1>>x2>>t0;
    pii res(1, 0), best(0, 0);
    ll sum = 0;
    for (int y2 = 0; y2 <= x2; ++y2) {
        ll y1 = x1;
        if (t0 > t1)
            y1 = min(x1, y2 * (t2 - t0) / (t0 - t1));
        if (y1 + y2 == 0)
            continue;
//        ll t = (y1 * t1 + y2 * t2) / (y1 + y2);
        pii cur(y1 * t1 + y2 * t2, y1 + y2);
        if (les(cur, res) || (eq(cur, res) && sum < y1 + y2)) {
            res = cur;
            sum = y1 + y2;
            best = pii(y1, y2);
        }
    }
    cout << best.first << " " << best.second << endl;
    return 0;
}