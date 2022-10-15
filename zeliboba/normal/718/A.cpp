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
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int q = -1;
int last = 0;
int dd = -1;

void mround(vi & v, int i) {
  for (int j = last; j <= i; ++j) v[j] = 0;
  last = i + 1;
  int add = 1;
  for (int j = i + 1; j < v.size(); ++j) {
    v[j] += add;
    add = v[j] / 10;
    v[j] %= 10;
    if (v[j] >= 5 && j < dd) q = j;
    if (!add) break;
  }
  if (add) v.push_back(add);
}

int main() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;
  vi v;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '.') {
      dd = 0;
    } else {
      v.push_back(s[i]-'0');
      if (dd >= 0) ++dd;
    }
  }
  reverse(v.begin(), v.end());
  for (int i = dd - 1; i >= 0; --i) if (v[i] >= 5) {
    mround(v, i);
    break;
  }
  while (t > 1) {
    if (q < 0) break;
    if (q < last) break;
    if (v[q] < 5) break;
    mround(v, q);
    --t;
  }
  reverse(v.begin(), v.end());
  while (!v.empty() && v.back() == 0 && dd) {
    v.pop_back();
    --dd;
  }
  for (int i = 0; i < v.size() - dd; ++i) {
    printf("%d", v[i]);
  }
  if (dd) printf(".");
  for (int i = v.size() - dd; i < v.size(); ++i) {
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}