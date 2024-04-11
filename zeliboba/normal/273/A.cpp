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
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    int m;
    cin >> m;
    vi w(m), h(m);
    ll ma = a[0];
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &w[i], &h[i]);
        --w[i];
        if (w[i] < a.size())
            ma = max(ma, (ll)a[w[i]]);
        cout << ma << endl;
        ma += h[i];
    }
    return 0;
}