#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const int MN = 1010;
int x[MN], y[MN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    ll u = max(x[n-1]-x[0], y[n-1]-y[0]);
    cout << u*u << endl;
    return 0;
}