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
#include <numeric>
#include <valarray>
#include <array>
using namespace std;

typedef long long ll;
ll MD;

struct SMatrix {
    typedef ll D;
    vector<valarray<D>> d;
    int N, M;
    SMatrix(int n, int m) {
        N = n; M = m;
        d.resize(n);
        for (int i = 0; i < N; i++) {
            d[i] = valarray<D>(D(0), m);
        }
    }

    valarray<D>& operator[](int p) {
        return d[p];
    }
    
    const valarray<D>& operator[](int p) const {
        return d[p];
    }
    
    SMatrix& operator=(const SMatrix &other) {
        assert(other.N == N && other.M == M);
        copy_n(other.d.begin(), N, d.begin());
        return *this;
    }

    SMatrix operator+(const SMatrix &right) {
        assert(right.N == N && right.M == M);
        SMatrix res(N, M);
        for (int i = 0; i < N; i++) {
            res[i] = (d[i]+right[i])%MD;
        }
        return res;
    }
    
    SMatrix operator*(const SMatrix &right) {
        assert(M == right.N);
        SMatrix res(N, right.M), r(right.M, right.N);
        for (int i = 0; i < right.M; i++) {
            for (int j = 0; j < right.N; j++) {
                r[i][j] = right[j][i]; 
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < right.M; j++) {
                res[i][j] = ((d[i]*r[j])%MD).sum()%MD;
            }
        }
        return res;
    }

    SMatrix pow(ll p) {
        assert(N == M);
        SMatrix res(N, M), buf = *this;
        for (int i = 0; i < N; i++) res[i][i] = D(1);
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

struct CombinationsM {
    vector<vector<ll>> d;
    CombinationsM(int N, int K, ll MD) {
        d = vector<vector<ll>>(N, vector<ll>(K));
        d[0][0] = 1;
        fill_n(&(d[0][1]), N-1, 0);
        for (int i = 1; i < N; i++) {
            d[i][0] = 1;
            for (int j = 1; j < K; j++) {
                d[i][j] = (d[i-1][j]+d[i-1][j-1]) % MD;
            }
        }
    }
};

const int MN = 1<<20;
ll d[21][MN] = {};
signed main() {
    int m;
    ll t;
    cin >> m >> t >> MD;
    int n = 1<<m;
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        d[0][i] = u;
    }
    ll e[21];
    for (int i = 0; i <= m; i++) {
        cin >> e[i];
    }
    auto c = CombinationsM(30, 30, MD);
    SMatrix mat(m+1, m+1);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= j; k++) {
                if (i-k+j-k < 0) continue;
                mat[i][j] += c.d[i][k]*c.d[m-i][j-k]%MD*e[i-k+j-k]%MD;
                mat[i][j] %= MD;
            }
        }
    }
    mat = mat.pow(t);

    for (int i = 0; i < m; i++) {
        int bm = 1<<i;
        for (int u = m; u > 0; u--) {
            for (int j = 0; j < n; j++) {
                d[u][j] += d[u-1][j^bm];
                d[u][j] %= MD;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        ll r = 0;
        for (int u = 0; u <= m; u++) {
            r += (mat[u][0]*d[u][j])%MD;
            r %= MD;
        }
        printf("%I64d\n", r);
    }
    return 0;
}