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
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii> vii;

ll inv(ll x) {
    ll res = 0;
    ll p10 = 1;
    while (x) {
        res += (9 - x % 10) * p10;
        x /= 10;
        p10 *= 10;
    }
    return res;
}

int main() {
    ll l, r;
    cin >> l >> r;
    ll ma = l * inv(l);
    ma = max(ma, r * inv(r));
    int cnt = 0;
    ll p10 = 1, r1 = r;
    while (r1 > 9) {
        r1 /= 10;
        ++cnt;
        p10 *= 10;
    }
    ll mid = 5 * p10;
    if (r > 5 * p10 && l < 5 * p10)
        ma = max(ma, mid * inv(mid));
    cout << ma << endl;
    return 0;
}