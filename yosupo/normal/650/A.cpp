#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 200200;
using P = pair<int, int>;

int n;
int a[MN], b[MN];


int xc[MN], yc[MN];

int main() {
    cin >> n;
    vector<int> xv, yv;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        xv.push_back(a[i]);
        yv.push_back(b[i]);
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());

    map<P, int> mp;
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(xv.begin(), xv.end(), a[i]) - xv.begin();
        b[i] = lower_bound(yv.begin(), yv.end(), b[i]) - yv.begin();
        mp[P(a[i], b[i])]++;
    }

    for (int i = 0; i < n; i++) {
        xc[a[i]]++;
        yc[b[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i < MN; i++) {
        ll A = xc[i];
        ans += A*(A-1)/2;
        ll B = yc[i];
        ans += B*(B-1)/2;
    }

    for (auto p: mp) {
        ll C = p.second;
        ans -= C*(C-1)/2;
    }

    cout << ans << endl;
    return 0;
}