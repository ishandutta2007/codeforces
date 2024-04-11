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
    vi v(4);
    for (int i = 0; i < 4; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << 4 - (unique(v.begin(), v.end()) - v.begin()) << endl;
    return 0;
}