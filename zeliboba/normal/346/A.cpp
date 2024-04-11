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
    int n;
    cin >> n;
    vi x(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &x[i]);
    int d = x[0], ma = x[0];
    for (int i = 1; i < x.size(); ++i) {
        d = __gcd(d, x[i]);
        ma = max(ma, x[i]);
    }
    int cnt = ma / d - n;
    if (cnt % 2) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    return 0;
}