#define NDEBUG

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;

const int N = 1<<7;

template <int N, ll MD>
struct SMatrix {
    using D = int;
    D *d;
    SMatrix() {
        d = new D[N*N]();
    }
    SMatrix(const SMatrix &r) {
        d = new D[N*N]();
        *this = r;
    }
    ~SMatrix() {
        delete[] d;
    }

    inline D* operator[](int p) {
        return d+(N*p);
    }
    
    inline D* operator[](int p) const {
        return d+(N*p);
    }
    
    SMatrix& operator=(const SMatrix &r) {
        memcpy(d, r.d, N*N*sizeof(D));
        return *this;
    }
    SMatrix operator+(const SMatrix &right) {
        SMatrix res;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res[i][j] = d[i*N+j]+right[i][j];
                if (res[i][j] >= MD) res[i][j] -= MD;
            }
        }
        return res;
    }
    
    SMatrix operator*(const SMatrix &right) {
        SMatrix res, r;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                r[i][j] = right[j][i]; 
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ll tmp = 0;
                for (int k = 0; k < N; k++) {
                    tmp += 1LL*d[i*N+k]*r[j][k];
                    if (tmp >= MD*MD) tmp -= MD*MD;
                }
                res[i][j] = tmp % MD;
            }
        }
        return res;
    }

    SMatrix pow(ll p) {
        SMatrix res, buf = *this;
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

const ll MD = 1e9+7;
SMatrix<N, MD> mt[7];
int main() {
    for (int i = 0; i < (1<<7); i++) {
        for (int j = 0; j < (1<<7); j++) {
            int ij = i&j;
            for (int k = 0; k < (1<<7); k++) {
                int kk = 1 | (k<<1);
                bool f = true;
                for (int l = 0; l < 7; l++) {
                    int lm = 1<<l;
                    if (ij&lm && kk&lm && kk&(lm<<1)) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    for (int m = 1; m <= 7; m++) {
                        int msk = ((1<<7)-1) & ~((1<<m)-1);
                        if (i < (1<<m) && j < (1<<m) && 
                            (1<<(m-1)) <= k && k < (1<<m)) {
                            assert((j | msk) < (1<<7));
                            mt[m-1][i | msk][j | msk]++;
                        }                            
                    }
                }
            }
        }
    }
    for (int u = 0; u < 7; u++) {
        int w;
        cin >> w;
        mt[u] = mt[u].pow(w);
    }
    for (int u = 1; u < 7; u++) {
        mt[0] = mt[0]*mt[u];
    }
    cout << mt[0][(1<<7)-1][(1<<7)-1] << endl;
}