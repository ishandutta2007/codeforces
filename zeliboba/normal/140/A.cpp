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

int main() {
    int n, R, r;
    cin >> n >> R >> r;
    if (n == 1) {
        if (R >= r)
            cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }
    if (R >= 2 * r && n * 2 * asin(r / (double)(R - r)) <= 2. * acos(-1.) + 1e-8)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}