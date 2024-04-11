#include <cstdio>
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

char a[1000005];
char b[1000005];
char was[2][1000005];

int f(char x) {
  if (x == 'N') return 0;
  if (x == 'W') return 1;
  if (x == 'E') return 2;
  if (x == 'S') return 3;
}

const ll P = 131;
const int M1 = 1000000021;
const int M2 = 989999993;
vii mhash(const vi & v) {
  vii h(v.size() + 1);
  for (int i = 0; i < v.size(); ++i) {
    h[i + 1] = pii((h[i].first*P + v[i]) % M1, (h[i].second*P + v[i]) % M2);
  }
  return h;
}

int n;
ll pw[2][1000005];

int len(int i, int j, const vii & h1, const vii & h2) {
  int l = 0, r = n;
  while (r - l > 1) {
    int t = (l + r) / 2;
    bool ok = 1;
    if (max(i, j) + t > n-1 || 
        (h1[i+t].first - h2[j+t].first - h1[i].first*pw[0][t] + h2[j].first*pw[0][t]) % M1 ||
        (h1[i+t].second - h2[j+t].second - h1[i].second*pw[1][t] + h2[j].second*pw[1][t]) % M2) {
      ok = 0;
    }
    if (ok) {
      l = t;
    } else {
      r = t;
    }
  }
  assert(l > 0 && max(i,j) + l <= n-1);
  return l;
}

vii h[2][2];
int main() {
    scanf("%d%s%s", &n, a, b);
    pw[0][0] = pw[1][0] = 1;
    for (int i = 1; i < n + 3; ++i) {
      pw[0][i] = pw[0][i-1]*P%M1;
      pw[1][i] = pw[1][i-1]*P%M2;
    }
    vvi d(2, vi(n-1));
    vvi di(2, vi(n-1));
    for (int i = 0; i < n-1; ++i) {
      d[0][i] = f(a[i]);
      d[1][i] = f(b[i]);
      di[0][n-2-i] = 3-d[0][i];
      di[1][n-2-i] = 3-d[1][i];
    }
    for (int i = 0; i < 2; ++i) {
      h[i][0] = mhash(d[i]);
      h[i][1] = mhash(di[i]);
    }
    int i = 0, j = 0;
    int t = 0;
    while (min(i, j) < n-1) {
//      cerr << i << ' ' << j << endl;
      if (i == n-1) {
        if (was[0][j]) break;
        was[0][j] = 1;
        t = 1;
      }
      if (j == n-1) {
        if (was[1][i]) break;
        was[1][i] = 1;
        t = 0;
      }
      if (t == 0) {
        if (j < n-1 && d[1][j] == d[0][i]) {
          ++j;
          ++i;
        } else if (j > 0 && di[1][n-j-1] == d[0][i]) {
          int l = len(i, n-1-j, h[0][0], h[1][1]);
          //l = 1;
          i += l;
          j -= l;
        } else {
          ++i;
        }
      } else {
        if (i < n-1 && d[1][j] == d[0][i]) {
          ++i;
          ++j;
        } else if (i > 0 && di[0][n-i-1] == d[1][j]) {
          int l = len(j, n-1-i, h[1][0], h[0][1]);
          //l = 1;
          j += l;
          i -= l;
        } else {
          ++j;
        }
      }
    }
    if (min(i, j) < n-1) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
    return 0;
}