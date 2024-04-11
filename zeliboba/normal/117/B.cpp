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

ll a,b,mod;

int d(int t) {
    if (t == mod)
        return 0;
    return t;
}

int main() {
    cin >> a >> b >> mod;
    ll m = 1000000000;
    if (mod <= b + 1) {
        cout << 2 << endl;
        return 0;
    }
    for (int i = 0; i <= min(a, mod); ++i) {
        if (d(mod - (i * m) % mod) > b) {
            printf("1 %09d\n", i);
            return 0;
        }
    }
    printf("2\n");
    return 0;
}