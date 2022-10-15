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
    vi v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.rbegin(), v.rend());
    int res = 0;
    while (v.size()) {
        ++res;
        int cur = 1;
        v.pop_back();
        for (int i = (int)v.size() - 1; i >= 0; --i) {
            if (v[i] >= cur) {
                ++cur;
                v.erase(v.begin() + i);
            }
        }
    }
    cout << res << endl;
    return 0;
}