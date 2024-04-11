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
    vii v(n);
    for (int i = 0; i < v.size(); ++i) {
        scanf("%d%d", &v[i].first, &v[i].second);
        v[i].first += v[i].second;
    }
    sort(v.begin(), v.end());
    int c = 1;
    double b = v[0].first;
    for (int i = 1; i < v.size(); ++i) if (v[i].first-2*v[i].second >= b) {
        ++c;
        b = v[i].first;
    }
    cout << c << endl;
    return 0;
}