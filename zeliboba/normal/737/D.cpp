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
#include <array>
#include <bitset>
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

int d[2][2001][100][2];

int main() {
  int n;
  scanf("%d", &n);
  vi a(n), s(n+1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s[i+1] = s[i] + a[i];
  }
  for (int k = 100; k >= 1; --k) {
    int t = k % 2;
    for (int l = n / 2; l >= 0; --l) for (int dif = min(k, n - 2*l); dif >= 0; --dif) {
      int rem = n - 2*l - dif;
      if (rem < k) {
        d[t][l][dif][0] = s[l] - (s.back() - s[n - l - dif]);
        d[t][l][dif][1] = s[l+dif] - (s.back() - s[n - l]);
        continue;
      }
//      if (k == 1 && l == 0 && dif == 0) cerr << t << l+dif << k - dif << endl;
      d[t][l][dif][0] = d[t][l+dif][k - dif][1];
      d[t][l][dif][1] = d[t][l+dif][k - dif][0];
      if (rem >= k+1) {
//        if (k == 1 && l == 0 && dif == 0) cerr << 1-t << l+dif << k+1 - dif << endl;
        d[t][l][dif][0] = max(d[t][l][dif][0], d[1-t][l+dif][k + 1 - dif][1]);
        d[t][l][dif][1] = min(d[t][l][dif][1], d[1-t][l+dif][k + 1 - dif][0]);
      }
    }
  }
//  cerr << d[1][0][1][1] << ' ' << d[0][0][2][1] << endl;
//  cerr << d[0][1][1][0] << ' ' << d[0][1][0][0] << endl;
//  cerr << d[1][0][1][1] << endl;
  printf("%d\n", d[1][0][0][0]);
  return 0;
}