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
    ll n, x, y;
    cin >> n >> x >> y;
    if (y < n || (y - n + 1) * (y - n + 1) + n - 1 < x) {
        cout << -1 << endl;
        return 0;
    } else {
        cout << y - n + 1 << endl;
        for (int i = 1; i < n; ++i)
            printf("1\n");
    }
    return 0;
}