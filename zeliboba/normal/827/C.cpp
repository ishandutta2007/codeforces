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
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const int N = 100001;
int s[4][11][N];

int add(int t, int m, int i, int val) {
  int r = i % m;
  i /= m;
  for (; i * m + r < N; i |= i + 1) {
    s[t][m][i * m + r] += val;
  }
}

int getsum(int t, int m, int i) {
  int r = i % m, sum = 0;
  i /= m;
  for (; i * m + r >= 0; i = (i & (i + 1)) - 1) {
    sum += s[t][m][i * m + r];
  }
  return sum;
}

int main() {
  std::ios::sync_with_stdio(false);
  string ss;
  int q;
  cin >> ss >> q;
  vi ind(256);
  ind['A'] = 0;
  ind['C'] = 1;
  ind['G'] = 2;
  ind['T'] = 3;
  vi v(ss.size());
  for (int i = 0; i < ss.size(); ++i) {
    v[i] = ind[ss[i]];
/*    for (int t = 0; t < 4; ++t) for (int j = 1; j <= 10; ++j) {
      if (i >= j) s[t][j][i] = s[t][j][i-j];
    }
    for (int j = 1; j <= 10; ++j) s[v[i]][j][i]++;*/
    for (int j = 1; j <= 10; ++j) add(v[i], j, i, 1);
  }
  for (int tt = 0; tt < q; ++tt) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int x;
      string c;
      cin >> x >> c;
      --x;
      int i = ind[c[0]];
//      s[x] = c[0];
      for (int j = 1; j <= 10; ++j) add(v[x], j, x, -1);
      v[x] = i;
      for (int j = 1; j <= 10; ++j) add(v[x], j, x, 1);
    } else {
      int l,r;
      string e;
      cin >> l >> r >> e;
      --l; --r;
      int m = e.size();
      vi y(e.size());
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        y[i] = ind[e[i]];
        int t = r;
        while (t >= 0 && t % m != (l + i) % m) --t;
        if (t >= 0) cnt += getsum(y[i], m, t);//s[y[i]][m][t];
        int t1 = l-1;
        while (t1 >= 0 && t1 % m != (l + i) % m) --t1;
        if (t1 >= 0) cnt -= getsum(y[i], m, t1);//s[y[i]][m][t];
//        cerr << tt << ' ' << i << ' ' << t1 << ' ' << t << ' ' << cnt << endl;
      }
      cout << cnt << endl;
    }
  }
  return 0;
}