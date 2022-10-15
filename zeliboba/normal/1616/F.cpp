#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int N = 8;
const int N = 257;
typedef array<int, N> va;
//const int mod = ;

void out(vector<va> a, int l = N) {
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < l; ++j) cerr << a[i][j] << ' ';
    cerr << endl;
  }
    cerr << endl;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n, m;
    cin >> n >> m;
    //vvi v(n, vi(n));
    vvi ind(n, vi(n, -1));
    vi e(m);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a; --b;
      ind[a][b] = ind[b][a] = i;
      //v[a][b] = v[b][a] = c;
      e[i] = c;
    }
    bool fail = 0;
    vector<va> A;
    va tmp;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (ind[i][j] >= 0) {
      for (int k = 0; k < n; ++k) if (ind[i][k] >= 0 && ind[j][k] >= 0) {
        vi x = {ind[i][j], ind[i][k], ind[j][k]};
        int s = 0;
        vi x1;
        for (int y : x) {
          if (e[y] >= 0) s += e[y];
          else x1.push_back(y);
        }
        s %= 3;
        if (x1.empty()) {
          if (s) fail = 1;
        } else {
          tmp.fill(0);
          for (int y : x1) tmp[y] = 1;
          tmp[N - 1] = (3 - s) % 3;
          A.push_back(tmp);
        }
      }
    }
    int b = 0;
    vi row(m, -1);
//    out(A);
    for (int i = 0; i < m && b < A.size(); ++i) {
      for (int r = b; r < A.size(); ++r) if (A[r][i] % 3) {
        swap(A[b], A[r]);
        break;
      }
      if (A[b][i] % 3) {
        for (int r = 0; r < A.size(); ++r) if (r != b && A[r][i] % 3) {
          int mul = A[r][i] == A[b][i] ? 1 : -1;
          for (int j = 0; j < N; ++j) A[r][j] = (A[r][j] + 3 - mul * A[b][j]) % 3;
          assert(A[r][i] == 0);
        }
        row[i] = b;
        ++b;
      }
    }
//    out(A);
    for (int r = b; r < A.size(); ++r) if (A[r][N - 1] % 3) fail = 1;
    for (int i = 0; i < m; ++i) if (e[i] == -1) {
      if (row[i] >= 0) e[i] = A[row[i]][N - 1] * A[row[i]][i] % 3;
      else e[i] = 0;
    }
    if (fail) cout << -1 << '\n';
    else {
      for (int i = 0; i < m; ++i) {
        if (e[i] == 0) e[i] = 3;
        cout << e[i] << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}