#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>
#include <valarray>
#include <list>

using namespace std;

typedef long long ll;

struct Pi {
    int x, y;
    Pi() {}
    Pi(int xx, int yy) {
        x = xx; y = yy;
    }
    bool operator<(const Pi &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }
    bool operator>(const Pi &r) const {
        if (x != r.x) return x > r.x;
        return y > r.y;
    }
};

struct Ti {
    int x, y, z;
    Ti() {}
    Ti(int xx, int yy, int zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator<(const Ti &r) const {
        if (x != r.x) return x < r.x;
        if (y != r.y) return y < r.y;
        return z < r.z;
    }
    bool operator>(const Ti &r) const {
        if (x != r.x) return x > r.x;
        if (y != r.y) return y > r.y;
        return z > r.z;
    }
};
const int MN = 100100;
ll a[MN], b[MN];
int main() {
    int n, m;
    cin >> n >> m;
    ll as = 0, bs = 0;
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        a[i] = u;
        as += u;
    }
    for (int i = 0; i < m; i++) {
        int u;
        scanf("%d", &u);
        b[i] = u;
        bs += u;
    }
    sort(a, a+n, greater<int>());
    sort(b, b+m, greater<int>());
    ll res = as+bs;
    ll ass = as;
    int mn = res/bs;
    for (int i = 0; i < min(n, mn+10); i++) {
        ass -= a[i];
        res = min(res, bs*(i+1)+ass);
    }
    ll bss = bs;
    int mm = res/as;
    for (int i = 0; i < min(m, mm+10); i++) {
        bss -= b[i];
        res = min(res, as*(i+1)+bss);
    }
    cout << res << endl;
    return 0;
}