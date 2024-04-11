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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

const int L = 500;
int d[1 << 16][L];

void upd(int &x, int y) {
  x = max(x, y);
}

int main() {
  int n;
  cin >> n;
  vi s(2), c(2);
  vector<array<int, 3>> v(n);
  for (int i = 0; i < n; ++i) {
    string st;
    int a,b;
    cin >> st >> a >> b;
    s[0] += a;
    s[1] += b;
    v[i][1] = a; v[i][2] = b;
    if (st == "R") ++c[0];
    else {
      ++c[1];
      v[i][0] = 1;
    }
  }
  const int MAX = 1e9;
  //int A[2] = {c[0]*(c[0]-1)/2 + 1, c[1]*(c[1]-1)/2 + 1};
  for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < L; ++i) {
      d[mask][i] = -MAX;
    }
  }
  d[0][0] = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    vi x;
    array<int, 2> cnt = {0, 0};
    array<int, 2> sum = {0, 0};
    for (int b = 0; b < n; ++b) {
      if (!(mask & (1 << b))) x.push_back(b);
      else {
        cnt[v[b][0]]++;
        sum[0] += v[b][1];
        sum[1] += v[b][2];
      }
    }
    for (int i = 0; i < L; ++i) if (d[mask][i] >= 0) {
      int D = max(sum[0] - i, sum[1] - d[mask][i]);
//      cerr << mask << ' ' << i << ' ' << d[mask][i] << endl;
      for (int b : x) {
        int r0 = min(cnt[0], v[b][1]);
        int r1 = min(cnt[1], v[b][2]);
        upd(d[mask | (1 << b)][i + r0], d[mask][i] + r1);
        /*int need0 = v[b][1] - r0 + sum[0] - i - d[mask][i * A[1] + j];
        int need1 = v[b][2] - r1 + sum[1] - j - d[mask][i * A[1] + j];
        int nind = (i + r0) * A[1] + j + r1;
        cerr << (mask | (1 << b)) << ' ' << need0 << ' ' << need1 << ' ' << nind << endl;
        upd(d[mask | (1 << b)][nind], d[mask][i * A[1] + j] + max(0, max(need0, need1)));*/
      }
    }
  }
  int res = MAX;
  for (int i = 0; i < L; ++i) {
    int j = d[(1 << n) - 1][i];
    if (j < 0) continue;
//    cerr << i << ' ' << j << ' ' << s[0] << ' ' << s[1] << endl;
    res = min(res, max(s[0] - i, s[1] - j));
  }
  cout << res + n << endl;
  return 0;
}