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

bool solve() {
    int n, m;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    if (s1[0] == '<' && s2[0] == '^') return false;
    if (s1[0] == '>' && s2[m-1] == '^') return false;
    if (s1[n-1] == '<' && s2[0] == 'v') return false;
    if (s1[n-1] == '>' && s2[m-1] == 'v') return false;
    return true;
}

int main() {
    if (solve()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}