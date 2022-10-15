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
    scanf("%d", &n);
    vvi x(n, vi(3));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i][0], &x[i][1]);
        x[i][2] = i + 1;
    }
//    vvi y = x;
    sort(x.begin(), x.end());
    int it = 0;
    int M = 1000;
    vi res;
    int r = 0;
    vvi ts;
    ts.reserve(1000000);
    for (int h = 0; h <= 1e6; h += M) {
        r = 1-r;
        ts.clear();
        for (; it < x.size() && x[it][0] <= h + M; ++it) {
            ts.push_back(x[it]);
            swap(ts.back()[0], ts.back()[1]);
        }
        if (r) sort(ts.begin(), ts.end());
        else sort(ts.rbegin(), ts.rend());
        for (int i = 0; i < ts.size(); ++i) res.push_back(ts[i][2]);
    }
    ll sumx = 0, sumy = 0;
    for (int i = 0; i < res.size(); ++i) {
/*        if (i) {
            sumx += abs(y[res[i]-1][0] - y[res[i-1]-1][0]);
            sumy += abs(y[res[i]-1][1] - y[res[i-1]-1][1]);
        }*/
        printf("%d ", res[i]);
    }
//    ll sum = sumx + sumy;
//    cerr << endl << sumx << ' ' << sumy << ' ' << sum << endl;
//    assert(sum < 24e8);
    return 0;
}