#include <iostream>
#include <cstdio>
#include <vector>
#include <valarray>
#include <cassert>

using namespace std;
typedef long long ll;


struct TMatrix {
    typedef ll D;
    const D INF = 1LL<<62;
    vector<valarray<D>> d;
    int N, M;
    TMatrix(int n, int m, bool f = false) {
        N = n; M = m;
        d.resize(n);
        for (int i = 0; i < N; i++) {
            d[i] = valarray<D>(INF, m);
        }
        if (f) {
            assert(N==M);
            for (int i = 0; i < N; i++) d[i][i] = 0;
        }
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
        TMatrix res(N, M, true), buf = *this;
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

int f[2<<23];
int d[100100];

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	int m = s.size();
	for (int i = 0; i < m; i++) {
		d[i] = s[i]-'A';
	}
	for (int i = 1; i <= 11; i++) {
		for (int j = 0; j <= m-i; j++) {
			int u = 0;
			for (int k = 0; k < i; k++) {
				u <<= 2;
				u += d[j+k];
			}
			u |= 1<<(2*i);
			f[u] = true;
		}
	}
	TMatrix g(4, 4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 10; k++) {
				//[i, ,, j]
				bool fl = true;
				for (int u = 0; u < 1<<(2*k); u++) {
					if (!f[1<<(2*k+4) | i<<(2*k+2) | u<<2 | j]) {
						fl = false;
					}
				}
				if (!fl) {
					g[i][j] = k+1;
					break;
				}
			}
		}
	}
	ll l = 0, r = n+1;
	while (r - l > 1) {
		ll md = (l+r)/2;
		TMatrix u = g.pow(md);
		ll k = 1LL<<62;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				k = min(k, u[i][j]);
			}
		}
		if (k < n) {
			l = md;
		} else {
			r = md;
		}
	}
	cout << r << endl;
	return 0;
}