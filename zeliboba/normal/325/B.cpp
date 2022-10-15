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
    ll n;
    cin >> n;
    vl ans;
    for (ll p2 = 1; p2 <= n+1; p2*=2) {
        ll add = p2 - 1;
        ll l = 1, r = 2e9;
        while (r - l > 1) {
            ll x = (r + l) / 2;
            if (n / x < (x-1)/2 + add) {
                r = x;
            } else l = x;
        }
        if (l%2 && l*(add+(l-1)/2) == n)
            ans.push_back(p2*l);
    }
    sort(ans.begin(), ans.end());
    if (ans.empty()) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < ans.size(); ++i)
            cout << ans[i] << endl;
    }
    return 0;
}