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
#include <unordered_map>
#include <queue>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
using namespace std;
typedef long double ld;
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
//const int mod = ;

bool ok(string s) {
  int bal = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '(') ++bal;
    else --bal;
    if (bal < 0) return false;
  }
  return bal == 0;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    string s;
    cin >> n >> s;
    string a(n, '('), b(n, '(');
    int c1 = 0;
    for (int i = 0; i < n; ++i) if (s[i] == '1') c1++;
    vi c(2);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (c[0] % 2) a[i] = ')';
        else b[i] = ')';
      } else {
        if (c[1] * 2 >= c1) a[i] = b[i] = ')';
      }
      ++c[s[i]-'0'];
    }
    if (ok(a) && ok(b)) {
      cout << "YES\n" << a << '\n' << b << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}