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
ll d1[MN], d2[MN];
int calc() {
    for (int i = MN-10; i >= 2; i--) {
        ll k = min(d1[i], d2[i]);
        d1[i] -= k; d2[i] -= k;
        if (d1[i] > 1000000) return 1;
        if (d1[i]) {
            d1[i-1] += d1[i];
            d1[i-2] += d1[i];
            d1[i] = 0;
        }
        if (d2[i] > 1000000) return -1;
        if (d2[i]) {
            d2[i-1] += d2[i];
            d2[i-2] += d2[i];
            d2[i] = 0;
        }
    }
    return 0;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    for (int i = 0; i < n1; i++) {
        d1[n1-i-1] = s1[i]-'0';
    }
    for (int i = 0; i < n2; i++) {
        d2[n2-i-1] = s2[i]-'0';
    }
    int u = calc();
    
    if (u == 1) {
        cout << '>' << endl;
        return 0;
    }
    if (u == -1) {
        cout << '<' << endl;
        return 0;
    }
    ll k = min(d1[1], d2[1]);
    d1[1] -= k; d2[1] -= k;
    k = min(d1[0], d2[0]);
    d1[0] -= k; d2[0] -= k;
    if (d1[1] == d2[1] && d1[0] == d2[0]) {
        cout << '=' << endl;
        return 0;
    }
    double q = (sqrt(5.0)+1)/2;
    double r1 = d1[1]*q+d1[0];
    double r2 = d2[1]*q+d2[0];
    if (r1 > r2) {
        cout << '>' << endl;
    } else {
        cout << '<' << endl;
    }
    return 0;
}