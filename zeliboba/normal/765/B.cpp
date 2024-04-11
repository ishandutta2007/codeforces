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

int main() {
  string s;
  cin >> s;
  vi was(26);
  bool ok = 1;
  for (int i = 0; i < s.size(); ++i) {
    int j = s[i] - 'a';
    was[j] = 1;
    for (int l = 0; l < j; ++l) if (!was[l]) {
      ok = 0;
      break;
    }
  }
  if (ok) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}