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
typedef long long ll;


/**
 *  with 
 */
struct Matrix {
    typedef ll D;
    const D INF = 1LL<<50;
    vector<valarray<D>> d;
    int N, M;
    Matrix(int N, int M) : N(N), M(M) {
        d.resize(N);
        for (int i = 0; i < N; i++) {
            d[i] = valarray<D>(-INF, M);
        }
    }

    valarray<D>& operator[](int p) {
        return d[p];
    }
    
    const valarray<D>& operator[](int p) const {
        return d[p];
    }
    
    Matrix& operator=(const Matrix &other) {
        assert(other.N == N && other.M == M);
        copy_n(other.d.begin(), N, d.begin());
        return *this;
    }

    Matrix operator*(const Matrix &right) {
        assert(M == right.N);
        Matrix res(N, right.M), r(right.M, right.N);
        for (int i = 0; i < right.M; i++) {
            for (int j = 0; j < right.N; j++) {
                r[i][j] = right[j][i]; 
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < right.M; j++) {
                res[i][j] = max(-INF, (d[i]+r[j]).max());
            }
        }
        return res;
    }

    Matrix pow(ll p) {
        assert(N == M);
        Matrix res(N, M), buf = *this;
        for (int i = 0; i < N; i++) res[i][i] = D(0);
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
const int MN = 110;
int n;
int a[MN];

int dp[MN][MN][MN];
bool used[MN][MN][MN];

int solve(int p, int b, int g) {
	if (p == n) return 0;
	if (used[p][b][g]) return dp[p][b][g];
	used[p][b][g] = true;
	int ma = solve(p+1, b, g);
	if (b <= a[p] && a[p] <= g) {
		ma = max(ma, 1+solve(p+1, a[p], g));
	}
	return dp[p][b][g] = ma;
}


int main() {
	int t;
	cin >> n >> t;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++) {
		// 0..n-1
		a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
		assert(0 <= a[i] && a[i] < n);
	}

	Matrix m(n+2, n+2);
	for (int i = 0; i < n+2; i++) {
		for (int j = i; j < n+2; j++) {
			m[i][j] = solve(0, i, j);
		}
	}

	m = m.pow(t);

	cout << m[0][n-1] << endl;
    return 0;
}