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
    vi v;
    for (int p = 2; p <= n; ++p) {
        bool ok = 1;
        for (int i = 2; i * i <= p; ++i) if (p % i == 0) {
            ok = 0;
        }
        if (ok) {
            int t = p;
            while (t <= n) {
                v.push_back(t);
                t *= p;
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) cout << v[i] << ' ';
    return 0;
}