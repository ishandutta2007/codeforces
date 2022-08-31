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
struct TMatrix {
    typedef ll D;
    const D EPS = 0;
    const D INF = 1LL<<50;
    vector<valarray<D>> d;
    int N, M;
    TMatrix(int n, int m) {
        N = n; M = m;
        d.resize(n);
        for (int i = 0; i < N; i++) {
            d[i] = valarray<D>(INF, m);
        }
        for (int i = 0; i < N; i++) d[i][i] = 0;
    }

    valarray<D>& operator[](int p) {
        return d[p];
    }
    
    const valarray<D>& operator[](int p) const {
        return d[p];
    }
    
    TMatrix& operator=(const TMatrix &other) {
        assert(other.N == N && other.M == M);
        copy_n(other.d.begin(), N, d.begin());
        return *this;
    }
    
    TMatrix operator*(const TMatrix &right) {
        assert(M == right.N);
        TMatrix res(N, right.M), r(right.M, right.N);
        for (int i = 0; i < right.M; i++) {
            for (int j = 0; j < right.N; j++) {
                r[i][j] = right[j][i]; 
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < right.M; j++) {
                res[i][j] = (d[i]+r[j]).min();
            }
        }
        return res;
    }

    TMatrix pow(ll p) {
        assert(N == M);
        TMatrix res(N, M), buf = *this;
        while(p != 0) {
            if (p % 2) {
                res = res*buf;
            }
            p /= 2;
            buf = buf*buf;
        }
        return res;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int a[20], b[20];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    TMatrix res(n*2, n*2);
    for (int i = 0; i < n*2; i++) {
        for (int j = 0; j < n*2; j++) {
            res[i][j] = (1LL<<50);
        }
    }
    for (int i = 0; i < (1<<n); i++) {
        int c = 0, cc = 0;
        ll d = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j)) {
                c++;
                d += a[j];
            } else {
                c--;
                d += b[j];
            }
            cc = min(c, cc);
        }
        for (int j = -cc; j < n*2-max(0, c); j++) {
            res[j][j+c] = min(res[j][j+c], d);
        }
    }
    res = res.pow(m);
    cout << res[0][0] << endl;
    return 0;
}