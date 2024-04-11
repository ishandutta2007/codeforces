#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
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
    ll n;
    cin >> n;
    vl div;
    for (int i = 1; i * i <= n; ++i) if (n % i == 0) {
        div.push_back(i);
        if (i * i != n)
            div.push_back(n / i);
    }
    ll mi = 1e9 * 1e9, ma = 0;
    for (int i = 0; i < div.size(); ++i) for (int j = 0; j < div.size(); ++j) if (n % (div[i] * div[j]) == 0) {
        ll a = div[i], b = div[j], c = n / (div[i] * div[j]);
        ll m = 2 * a * c + b * c + 2 * a * b + 4 * a + 2 * b + 2 * c + 4;
        mi = min(mi, m);
        ma = max(ma, m);
    }
    cout << mi << " " << ma << endl;
    return 0;
}