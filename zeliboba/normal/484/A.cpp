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
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        ll l,r;
        cin >> l >> r;
        ll res = 0;
        for (int b = 62; b >= 0; --b) {
            ll p2 = 1LL << b;
            if (l >= p2) {
                res += p2;
                r -= p2;
                l -= p2;
            } else if (r >= p2) {
                if (r == 2*p2-1) {
                    res += r;
                } else {
                    res += p2-1;
                }
                break;
            }
        }
        cout << res << endl;
    }
    return 0;
}