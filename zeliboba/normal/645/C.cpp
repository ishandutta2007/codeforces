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

char s[200000];
int main() {
  int n, k;
  scanf("%d%d%s", &n, &k, s);
  ++k;
  int res = n;
  vi v;
  for (int i = 0; i < n; ++i) if (s[i] == '0') v.push_back(i);
  for (int i = 0; i + k <= v.size(); ++i) {
    int l = v[i], r = v[i+k-1];
    int m = lower_bound(v.begin(), v.end(), (l + r + 1) / 2) - v.begin();
    //int m = lower_bound(v.begin(), v.end(), (l + r) / 2) - v.begin();
    res = min(res, min(max(r - v[m], v[m] - l), max(r - v[m-1], v[m-1] - l)));
  }
  cout << res << endl;
  return 0;
}