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
    int n;
    cin >> n;
    vi a(n);
    vi v(5);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ++v[a[i]];
    }
    int ans = v[4] + v[3];
    v[1] = max(0, v[1] - v[3]);
    ans += v[2] / 2;
    v[2] %= 2;
    if (v[2]) {
        ans++;
        v[1] = max(0, v[1] - 2);
    }
    ans += (v[1] + 3) / 4;
    cout << ans << endl;
    return 0;
}