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
#include <valarray>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

template<ll MD>
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
                res[i][j] = (d[i]*r[j]%MD).sum()%MD;
            }
        }
        return res;
    }

    SMatrix operator*(const D x) {
        SMatrix res(N, M);
        for (int i = 0; i < N; i++) {
            res[i] = (d[i]*x)%MD;
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

template<int N, int K, ll MOD>
struct CombinationsM {
    ll data[N][K];
    CombinationsM() {
        data[0][0] = 1;
        fill_n(&(data[0][1]), N-1, 0);
        for (int i = 1; i < N; i++) {
            data[i][0] = 1;
            for (int j = 1; j < K; j++) {
                data[i][j] = (data[i-1][j]+data[i-1][j-1]) % MOD;
            }
        }
    }
    ll* operator[](int n) {
        return data[n];
    }
    const ll* operator[](int n) const {
        return data[n];
    }
};

const ll MD = 1e9+7.1;
const int MK = 55;
SMatrix<MD> s(MK*2+1, MK*2+1), x(MK*2+1, 1);
CombinationsM<MK+2, MK+2, MD> c;
ll f[MK+10];
int main() {
    ll n, k;
    cin >> n >> k;
    if (n == 1) {cout << 1 << endl; return 0;}
    f[0] = 1;
    for (int i = 1; i < MK+10; i++) {
        f[i] = f[i-1]*2%MD;
    }
    x[0] = 1;
    for (int i = 0; i < MK; i++) {
        x[i*2+1][0] = 1;
    }
    for (int i = 0; i < MK; i++) {
        x[i*2+2][0] = 1+f[i+1];
    }
    s[0][0] = 1;
    for (int i = 0; i < MK; i++) {
        s[i*2+1][i*2+2] = 1;
    }
    for (int i = 0; i < MK; i++) {
        s[i*2+2][0] = 1+f[i];
        for (int j = 0; j <= i; j++) {
            s[i*2+2][j*2+1] = c[i][j]*f[i-j]%MD;
            s[i*2+2][j*2+2] = c[i][j];
        }
    }
    s = s.pow(n-2);
    x = s*x;
    cout << x[k*2+2][0] << endl;
    return 0;
}