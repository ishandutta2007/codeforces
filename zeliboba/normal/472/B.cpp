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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n, k;
    cin >> n >> k;
    vi f(n);
    for (int i = 0; i < n; ++i) cin >> f[i];
    sort(f.rbegin(), f.rend());
    ll sum = 0;
    for (int i = 0; i < n; i += k)
        sum += 2*(f[i]-1);
    cout << sum << endl;
    return 0;
}