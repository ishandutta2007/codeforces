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
int m;

ll mpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % m;
        x = x * x % m;
        n /= 2;
    }
    return res;
}

int main() {
    ll n;
    cin >> n >> m;
    cout << (mpow(3, n) + m - 1) % m << endl;
    return 0;
}