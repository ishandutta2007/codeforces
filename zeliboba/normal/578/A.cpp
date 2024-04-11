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

int main() {
    int a, b;
    cin >> a >> b;
    if (b > a) {
        cout << -1 << endl;
        return 0;
    }
    if (a == b) {
        cout << b << endl;
        return 0;
    }
    int t = (a - b) / b;
    if (t % 2) --t;
    double x = t ? (a - b) / (double)t : 1e18;
//    cerr << t << ' ' << x << endl;
    t = (a + b) / b;
    if (t % 2) --t;
    double y = (a + b) / (double)t;
//    cerr << t << ' ' << y << endl;
    printf("%.12lf\n", min(x, y));
    return 0;
}