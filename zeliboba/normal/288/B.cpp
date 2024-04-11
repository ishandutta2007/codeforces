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
const int mod = 1000000007;

ll mpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n&1)
            res=res*x%mod;
        x=x*x%mod;
        n/=2;
    }
    return res;
}

int main() {
    int n,k;
    cin >> n >> k;
    cout << mpow(k, k-2) * k % mod * mpow(n-k, n-k) % mod << endl;
    return 0;
}