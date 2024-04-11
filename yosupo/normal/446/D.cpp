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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const double EPS = 1e-9;

struct SMatrix {
    typedef double D;
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
            res[i] = d[i]+right[i];
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
                res[i][j] = (d[i]*r[j]).sum();
            }
        }
        return res;
    }

    SMatrix operator*(const D x) {
        SMatrix res(N, M);
        for (int i = 0; i < N; i++) {
            res[i] = d[i]*x;
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
    
    void mulL(int i, D x) {
        d[i] *= x;
    }
    
    void excL(int i, int j) {
        swap(d[i], d[j]);
    }
    //line i -> i+(j*x)
    void addL(int i, int j, D x) {
        d[i] += d[j]*x;
    }
    
    int inverse() {
        assert(N == M);
        SMatrix r(N, N);
        for (int i = 0; i < N; i++) r[i][i] = D(1);
        for (int i = 0; i < N; i++) {
            if (d[i][i] == 0) {
                int j;
                for (j = i+1; j < N; j++) {
                    if (abs(d[i][j]) > EPS) { //TODO: EPS
                        r.excL(i, j);
                        excL(i, j);
                        break;
                    }
                }
                if (j == N) return i;
            }
            r.mulL(i, 1/d[i][i]);
            mulL(i, 1/d[i][i]);
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                r.addL(j, i, -d[j][i]);
                addL(j, i, -d[j][i]);
            }
        }
        *this = r;
        return N;
    }
};

const int MN = 512;
int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    SMatrix A(n,n), B(n,n), C(n,n), D(n,n), E(n,n) , nE(n,n);
    for (int i = 0; i < n; i++) D[i][i] = E[i][i] = nE[i][i] = 1.0;
    nE = nE*(-1);

    int d[MN];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    int count[MN] = {};
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        if (!d[a]) {
            A[a][b] += 1;
        } else {
            B[a][b] += 1;
        }
        if (!d[b]) {
            A[b][a] += 1;
        } else {
            B[b][a] += 1;
        }
        count[a]++; count[b]++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] /= count[i];
            B[i][j] /= count[i];
        }
    }
    A = E+(A*(-1));
    A.inverse();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!d[i] && !d[j]) {
                A[i][j] = 0.0;
            }
        }
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (d[i]) v.push_back(i);
    }

    int a = v.size();
    SMatrix F(a,a);
    C = B*A;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            F[i][j] = C[v[i]][v[j]];
        }
    }
    F = F.pow(k-2);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            D[v[i]][v[j]] = F[i][j];
        }
    }
    D = A*D;
    printf("%.20f\n", D[0][n-1]);

    return 0;
}