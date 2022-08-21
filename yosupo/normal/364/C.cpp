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

template<class T>
struct Pi {
    T x, y;
    Pi() {}
    Pi(T xx, T yy) {
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
    bool operator==(const Pi &r) const {
        if (x != r.x) return false;
        return y == r.y;
    }
};

template<class T>
struct Ti {
    T x, y, z;
    Ti() {}
    Ti(T xx, T yy, T zz) {
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
    bool operator==(const Ti &r) const {
        if (x != r.x) return false;
        if (y != r.y) return false;
        return z == r.z;
    }
};

const int MK = 5050;
bool dp[MK*MK*2][5];
int prim[] = {2,3,5,7,11};
int main() {
    int k;
    cin >> k;
    int kk = (k+1)/2;
    int mx = k*k*2;
    vector<int> res;
    int mp = 4;
    if (k <= 100) {
        mp = 2;
    } else if (k <= 700) {
        mp = 3;
    }
    for (int cp = mp; cp >= 0; cp--) {
        int num = 0;
        for (int x = 1; x <= mx/prim[cp]; x++) {
            int y = x;
            for (int i = 0; i <= cp; i++) {
                int d = prim[i];
                while (!(y % d)) {
                    y /= d;
                }
            }
            if (y == 1) {
                num++;
                assert(x*prim[cp] <= mx);
                res.push_back(x*prim[cp]);
                if (res.size() == k) break;
                if (num == kk) break;
            }
        }
        if (res.size() == k) break;
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    for (int d: res) {
        printf("%d ", d);
    }
    printf("\n");
    return 0;
    assert(res.size() == k);
    cout << res.size() << endl;
    int count[5] = {};
    for (int d: res) {
        for (int i = 0; i < 5; i++) {
            int p = prim[i];
            if (!(d % p)) {
                count[i]++;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", i, count[i]);
        assert (count[i] >= kk || count[i] == 0);
    }
    return 0;
}