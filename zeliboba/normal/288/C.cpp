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
    ll n;
    cin >> n;
    cout << n*(n+1) << endl;
    vi v(n+1);
    int t = n;
    while (t > 0) {
        int p2 = 1;
        while (p2 * 2 <= t)
            p2 *= 2;
        for (int i = 0; i + p2 <= t; ++i) {
            v[i+p2] = p2 - i - 1;
            v[p2-i-1] = i+p2;
        }
        t -= (t-p2+1) * 2;
    }
    for (int i = 0; i <= n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}