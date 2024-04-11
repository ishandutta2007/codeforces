#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 1e9 + 7;
template<typename T>
T add(T x) {
    return x;
}
template<typename T, typename... Ts>
T add(T x, Ts... y) {
    T res = x + add(y...);
    if (res >= mod)
        res -= mod;
    return res;
}
template<typename T, typename... Ts>
T sub(T x, Ts... y) {
    return add(x, mod - add(y...));
}
template<typename T, typename... Ts>
void udd(T &x, Ts... y) {
    x = add(x, y...);
}
template<typename T>
T mul(T x) {
    return x;
}
template<typename T, typename... Ts>
T mul(T x, Ts... y) {
    return (x * 1ll * mul(y...)) % mod;
}
template<typename T, typename... Ts>
void uul(T &x, Ts... y) {
    x = mul(x, y...);
}
int bin(int a, ll deg) {
    int r = 1;
    while (deg) {
        if (deg & 1)
            uul(r, a);
        deg >>= 1;
        uul(a, a);
    }
    return r;
}
int inv(int x) {
    assert(x);
    return bin(x, mod - 2);
}

const int N = 105;

struct Matrix {
  int a[N][N];

  Matrix() {
    memset(a, 0, sizeof(a));
  }

  const int* operator[](int id) const {
    return a[id];
  }

  int* operator[](int id) {
    return a[id];
  }

  Matrix operator*(const Matrix& m) const {
    Matrix res;
    forn (i, N)
      forn (j, N)
        forn (k, N)
          udd(res[i][k], mul((*this)[i][j], m[j][k]));
    return res;
  }
};

int init[N];
int end[N];
int ways[N];
Matrix A, B;

int mid[2100100];

int main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  int n, l, m;
  cin >> n >> l >> m;
  forn (i, n) {
    int x;
    cin >> x;
    init[x % m]++;
  }
  forn (i, n) {
    int x;
    cin >> x;
    mid[i] = x;
    forn (j, m)
      A[j][(j + x) % m]++;
  }
  int deg = l - 2;
  forn (i, m)
    B[i][i] = 1;
  while (deg) {
    if (deg & 1)
      B = B * A;
    deg >>= 1;
    A = A * A;
  }

  forn (i, m)
    forn (j, m) {
      udd(ways[j], mul(init[i], B[i][j]));
    }

  int res = 0;
  forn (i, n) {
    int x;
    cin >> x;
    x += mid[i];
    int need = (m - x % m) % m;
    udd(res, ways[need]);
  }
  cout << res << '\n';
}