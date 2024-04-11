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
    vi w(n);
    vi c(2000000);
    for (int i = 0; i < w.size(); ++i) {
        scanf("%d", &w[i]);
        ++c[w[i]];
    }
    int res = 0;
    for (int i = 0; i+1 < c.size(); ++i) {
        if (c[i] & 1) ++res;
        c[i+1] += c[i]/2;
    }
    cout << res << endl;
    return 0;
}