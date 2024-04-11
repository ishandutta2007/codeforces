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
const ll MAX = 2e18;

vl c(51);

int main() {
    ll n, k;
    cin >> n >> k;
    c[0] = c[1] = 1;
    for (int i = 2; i < c.size(); ++i) {
        c[i] = 0;
        for (int j = 1; j <= 2; ++j) {
            c[i] = min(MAX, c[i] + c[i-j]);
        }
//        cerr << i << ' ' << c[i] << endl;
    }
    int add = 1;
    vi res;
    while (n) {
        ll sum = 0;
        for (int l = 1; l <= 2; ++l) {
            sum += c[n-l];
//            cerr << k << ' ' << l << ' ' << sum << ' ' << n << endl;
            if (sum >= k) {
                for (int j = 0; j + 1 < l; ++j) {
                    res.push_back(add + j + 1);
                }
                res.push_back(add);
                k -= sum - c[n-l];
                add += l;
                n -= l;
                break;
            }
        }
    }
    for (int i = 0; i < res.size(); ++i) cout << res[i] << ' ';
    return 0;
}