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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    while (a + b && c + d) {
        if (a >= c && a) --a;
        else --b;
        if (c && d && (c != a + 1 || d != b + 1)) {
            --c; --d;
        } else if (c) {
            --c;
        } else {
            --d;
        }
    }
    if (a + b == 0) {
        cout << "Polycarp\n";
    } else {
        cout << "Vasiliy\n";
    }
    return 0;
}