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
    int n;
    cin >> n;
    int N = (1 << n);
    vl a(2*N);
    for (int i = 2; i < a.size(); ++i) cin >> a[i];
    ll res = 0;
    for (int i = N-1; i >= 1; --i) {
        a[i] += max(a[2*i], a[2*i+1]);
        res += abs(a[2*i] - a[2*i+1]);
    }
    cout << res << endl;
    return 0;
}