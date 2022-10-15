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
    vi v;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a)
            v.push_back(a);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i + 1 < v.size(); ++i) {
        if (v[i] == v[i+1])
            ++cnt;
        if (i + 2 < v.size() && v[i] == v[i+2]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}