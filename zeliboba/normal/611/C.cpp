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

char s[505][505];
char s1[505][505];

vvi f(int h, int w) {
  vvi r(h, vi(w + 1));
  for (int i = 0; i < h; ++i) {
    for (int j = 1; j < w; ++j) {
      r[i][j + 1] = r[i][j];
      if (s[i][j] == '.' && s[i][j-1] == '.') ++r[i][j+1];
    }
  }
  return r;
}

int main() {
  int h,w, Q;
  cin >> h >> w;
  for (int i = 0; i < h; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < w; ++j) s1[i][j] = s[i][j];
  }
  vvi r = f(h, w);
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
    s[j][i] = s1[i][j];
  }
  vvi c = f(w, h);
  cin >> Q;
  for (int q= 0; q < Q; ++q) {
    int r1,c1,r2,c2;
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    --r1;--c1;--r2;--c2;
    int res = 0;
    for (int i = r1; i <= r2; ++i) {
      res += r[i][c2 + 1] - r[i][c1];
      if (c1 && s1[i][c1] == '.' && s1[i][c1-1] == '.') --res;
    }
    for (int i = c1; i <= c2; ++i) {
      res += c[i][r2 + 1] - c[i][r1];
      if (r1 && s[i][r1] == '.' && s[i][r1-1] == '.') --res;
    }
    printf("%d\n", res);
  }
  return 0;
}