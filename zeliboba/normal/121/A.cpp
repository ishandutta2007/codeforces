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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    ll l,r;
    cin >> l >> r;
    vll v(1, 0);
    for (int l = 1; l <= 10; ++l) {
        for (int mask = 0; mask < (1 << l); ++mask) {
            ll t = 0;
            for (int i = 0; i < l; ++i) {
                t *= 10;
                if (mask & (1 << i))
                    t += 4;
                else t += 7;
            }
            v.push_back(t);
        }
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for (vll::iterator it = lower_bound(v.begin(), v.end(), l); it <= upper_bound(v.begin(), v.end(), r); ++it) {
        sum += *it * (min(*it, r) - max(l - 1, *(it - 1)));
    }
    cout << sum << endl;
    return 0;
}