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
typedef Pi<int> P;
const int MN = 1010;
int n, m;
bool g[MN][MN];
int dx[MN][MN], dy[MN][MN];
int sx = -1, sy;
int xc = 0;
int solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) {
                sy = i;
                sx = j;
                break;
            }
        }
        if (sx >= 0) {
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) {
                xc++;
            }
            dx[i][j] = dy[i][j] = 0;
        }
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = m-2; j >= 0; j--) {
            if (!g[i][j]) continue;
            dx[i][j] = dx[i][j+1]+1;
            dy[i][j] = dy[i+1][j]+1;
        }
    }
    vector<P> r;
    for (int i = 1; i <= dx[sy][sx]; i++) {
        r.push_back(P(i, dy[sy][sx]));
    }
    for (int j = 1; j <= dy[sy][sx]; j++) {
        r.push_back(P(dx[sy][sx], j));
    }
    int res = MN*MN*2;
    //printf("start %d %d\n", sx, sy);
    for (P p: r) {
        //printf("%d %d\n", p.x, p.y);
        int x = sx, y = sy;
        int ss = p.x*p.y;
        bool ok = true;
        for (int i = 0; i < p.x; i++) {
            if (dy[sy][sx+i] < p.y) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        while (true) {
            if (ss == xc) {
                res = min(res, p.x*p.y);
            }
            bool f1 = p.y <= dy[y][x+p.x];
            bool f2 = p.x <= dx[y+p.y][x];
            if (f1 && f2) break;
            if (!f1 && !f2) break;
            if (f1) {
                ss += p.y;
                x++;
            } else {
                ss += p.x;
                y++;
            }
        }
    }
    if (res == MN*MN*2) return -1;
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            g[i][j] = (s[j] == 'X');
        }
    }
    n++; m++;
    cout << solve() << endl;
    return 0;
}