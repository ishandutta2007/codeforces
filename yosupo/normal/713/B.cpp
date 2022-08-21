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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

using Q = array<int, 4>;

int n;
vector<int> c[4];

int query(Q q) {
    cout << "?";
    for (int i = 0; i < 4; i++) {
        cout << " " << q[i];
    }
    cout << endl;
    int a;
    cin >> a;
    return a;
}

void ans(Q q1, Q q2) {
    cout << "!";
    for (int i = 0; i < 4; i++) {
        cout << " " << q1[i];
    }
    for (int i = 0; i < 4; i++) {
        cout << " " << q2[i];
    }
    cout << endl;
}

int query(int d, int dis) {
    Q q{{1, 1, n, n}};
    if (d < 2) {
        q[d] = 1+dis;
    } else {
        q[d] = n-dis;
    }
    return query(q);
}

int main() {
    cin >> n;
    for (int d = 0; d < 4; d++) {
        //0
        int l, r;
        l = 0; r = n;
        while (r-l > 1) {
            int md = (l+r)/2;
            if (query(d, md) >= 1) {
                l = md;
            } else {
                r = md;
            }
        }
        if (d < 2) {
            c[d].push_back(l+1);
        } else {
            c[d].push_back(n-l);
        }
        l = 0; r = n;
        while (r-l > 1) {
            int md = (l+r)/2;
            if (query(d, md) >= 2) {
                l = md;
            } else {
                r = md;
            }
        }
        if (d < 2) {
            c[d].push_back(l+1);
        } else {
            c[d].push_back(n-l);
        }
    }

    for (int i = 0; i < (1<<4); i++) {
        Q q1, q2;
        for (int d = 0; d < 4; d++) {
            if (i & (1<<d)) {
                q1[d] = c[d][0];
                q2[d] = c[d][1];
            } else {
                q1[d] = c[d][1];
                q2[d] = c[d][0];
            }
        }
        if (q1[0] > q1[2]) continue;
        if (q1[1] > q1[3]) continue;
        if (q2[0] > q2[2]) continue;
        if (q2[1] > q2[3]) continue;
        if (query(q1) == 1 && query(q2) == 1) {
            ans(q1, q2);
            return 0;
        }
    }
    return 0;
}