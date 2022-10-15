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
    int n = 1000;
    cout << n - 2 + n - 1 << endl;
    for (int i = n - 1; i >= 2; --i) {
        for (int y = 1; y <= 2; ++y) {
            cout << i << ' ' << y << ' ';
        }
        cout << endl;
    }
    for (int i = 2; i <= n; ++i) {
        for (int y = 1; y <= 2; ++y) {
            cout << i << ' ' << y << ' ';
        }
        cout << endl;
    }
    return 0;
}