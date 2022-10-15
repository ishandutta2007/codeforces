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
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    ll a,b,m,r;
    cin >> a >> b >> m >> r;
    vi was(m);
    r %= m;
    int t = 1;
    while (was[r] == 0) {
        was[r] = t;
        ++t;
        r = (a * r + b) % m;
    }
    cout << t - was[r] << endl;
    return 0;
}