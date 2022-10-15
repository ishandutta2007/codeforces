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
    int n, m, x1, x2, y1, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int d = abs(x1 - x2) + abs(y1 - y2);
    bool oneline = (x1 == x2) || (y1 == y2);
    int neig = min(abs(x1 - x2), abs(y1 - y2));
    if (d <= 4 || (d == 5 && neig > 0) || (d == 6 && neig > 1)) {
        cout << "First\n";
    } else cout << "Second\n";
    return 0;
}