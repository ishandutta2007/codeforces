#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <complex>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;
#define int long long
const int MN = 1100000;
int d[MN];
int a[MN], b[MN], c[MN];
signed main() {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        s += d[i];
    }
    sort(d, d+n, greater<int>());
    a[0] = b[0] = c[0] = 0;
    for (int i = 0; i <= n; i++) {
        a[i+1] = a[i], b[i+1] = b[i], c[i+1] = c[i];
        a[i+1] += 4-d[i];
        if (d[i] == 4) {
            c[i+1]++;
        } else {
            b[i+1] += 3-d[i];
        }
        assert(a[i+1]>=a[i]);
        assert(b[i+1]>=b[i]);
        assert(c[i+1]>=c[i]);
    }
    int r = s*2;
    for (int i = 0; i <= n; i++) {
        int u = s-4*i;
        if (u < 0) break;
        if (u % 3) continue;
        u /= 3;
        if (n < i+u) continue;
        int bb = b[i+u]-b[i], cc = c[i+u]-c[i];
        r = min(r, a[i]+bb);
    }
    if (r == s*2) {
        cout << -1 << endl;
    } else {
        cout << r << endl;
    }
    return 0;
}