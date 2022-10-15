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

ll mmod (ll x, ll n) {
    return (x % n + n) % n;
}

int main() {
    ll a,b,x1,y1,x2,y2;
    int ma = 1000000000;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    ll s1 = x1 + y1, s2 = x2 + y2;
    ll d1 = x1 - y1, d2 = x2 - y2;
    if (s1 > s2)
        swap(s1, s2);
    if (d1 > d2)
        swap(d1, d2);
    ll n1 = (s2 - mmod(s2, 2*a)) / (2 * a) - (s1 - mmod(s1, 2 * a)) / (2 * a);
    ll n2 = (d2 - mmod(d2, 2*b)) / (2 * b) - (d1 - mmod(d1, 2 * b)) / (2 * b);
    if (n1 == 0 && a == 1)
        n1 = 1;
    if (n2 == 0 && b == 1)
        n2 = 1;
    cout << max(n1, n2) << endl;
    return 0;
}