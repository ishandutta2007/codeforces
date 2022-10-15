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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

int last;
int read() {
  cin >> last;
  return last;
}

vi v;

bool win() {
  bool ok = 1;
  for (int i = 1; i + 1 < v.size(); ++i) if (v[i] > v[i+1] || v[i] == -1) {
    ok = 0; break;
  }
  return ok;
}

void answer(int pos) {
  v[pos] = last;
  cout << pos << endl;
  fflush(stdout);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, c;
  cin >> n >> m >> c;
  v.assign(n + 1, -1);
  for (int turn = 1; turn <= m && !win(); ++turn) {
//    for (int i = 1; i <= n; ++i) cerr << v[i] << ' '; cerr << endl;
    int x = read();
    if (x <= c/2) {
      for (int i = 1; i <= n; ++i) {
        if (x < v[i] || v[i] == -1) {
          answer(i); break;
        }
      }
    } else {
      for (int i = n; i >= 1; --i) {
        if (x > v[i] || v[i] == -1) {
          answer(i); break;
        }
      }
    }
  }
  return 0;
}