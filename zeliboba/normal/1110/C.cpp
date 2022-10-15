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
typedef long double ld;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  map<int, int> saved;
  for (int pw = 3; pw <= (1 << 25) - 1; pw = pw * 2 + 1) {
    int ma = 1;
    for (int i = 1; i <= pw / 2; ++i) if (pw % i == 0) {
      ma = max(ma, i);
    }
    saved[pw] = ma;
//    cerr << pw << ' ' << ma << endl;
  }
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    int pw = 1;
    while (pw * 2 <= a) {
      pw *= 2;
    }
//    cerr << a << ' ' << pw << endl;
    if (a != pw * 2 - 1) {
      cout << pw * 2 - 1 << '\n';
    } else {
      cout << saved[a] << '\n';
    }
  }
  return 0;
}