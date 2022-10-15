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

char s[1000000];

int main() {
  int n,a,b,k;
  scanf("%d%d%d%d%s", &n,&a,&b,&k,s);
  vi v(1, 0), p(1, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      v.push_back(0);
      p.push_back(i + 1);
    } else {
      ++v.back();
    }
  }
  int c = 0;
  for (int x : v) if (x >= b) {
    c += x / b;
  }
  printf("%d\n", c - a + 1);
  int rem = c - a + 1;
  for (int it = 0; it < v.size(); ++it) {
    int x = v[it];
    if (x >= b) {
      int d = min(x / b, rem);
      for (int i = 0; i < d; ++i) {
        printf("%d ", 1 + p[it] + b-1 + i * b);
      }
      rem -= d;
    }
  }
  return 0;
}