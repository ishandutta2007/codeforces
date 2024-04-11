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
    ll n, m;
    cin >> n >> m;
    vi res(n);
    vl p2(60, 1);
    for (int i = 1; i < p2.size(); ++i) p2[i] = p2[i-1] * 2;
    int b = 0, e = n-1;
    while (e >= b) {
        if (e == b) {
            res[b] = n;
            break;
        }
//        cerr << b << ' ' << e << ' ' << m << ' ' << p2[e-b-1] << endl;
        if (m > p2[e-b-1]) {
            m -= p2[e-b-1];
            res[e] = n - (e - b);
            --e;
        } else {
            res[b] = n - (e - b);
            ++b;
        }
    }
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    return 0;
}