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

int main() {
  int n;
  cin >> n;
  vi p(n);
  int c = 0;
  vi w(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    if (p[i] == i) {
      ++c;
    } else w[p[i]] = 1;
  }
  int x = 0;
  for (int i = 0; i < n; ++i) x += w[i];
  cout << c + x/2 << endl;
  return 0;
}