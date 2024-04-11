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

int main() {
  //  std::ios::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  int rem = 240 - k, c = 0;
  for (int i = 1; i <= n; ++i) {
    if (rem >= 5*i) {
      rem -= 5*i;
      ++c;
    } else break;
  }
  cout << c << endl;
  return 0;
}