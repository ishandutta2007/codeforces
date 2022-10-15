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
    ll n, k;
    cin >> n >> k;
    --n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (k*(k-1) / 2 < n) {
        cout << -1 << endl;
        return 0;
    }
    ll l = 0, r = k;
    while(r-l>1) {
        ll x = (r+l)/2;
        if (x*(2*(k-1)-x+1)/2 < n)
            l = x;
        else r = x;
    }
    cout << r << endl;
    return 0;
}