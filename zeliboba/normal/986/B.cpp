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
//const int mod = ;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }
  vi was(n);
  int sg = 0;
  for (int i = 0; i < n; ++i) if (!was[i]) {
    int cur = i, len = 0;
    while (!was[cur]) {
      ++len;
      was[cur] = 1;
      cur = a[cur];
    }
    sg += len - 1;
  }
  if (n % 2 == sg % 2) {
    cout << "Petr\n";
  } else {
    cout << "Um_nik\n";
  }
  return 0;
}