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

void fail() {
  cout << ":(\n";
  exit(0);
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string t;
  cin >> t;
  int n = t.size(), na = 0;
  for (char x : t) na += x != 'a';
  if (na % 2) fail();
  string s = "", s1 = "";
  int cnt = 0;
  for (char x : t) {
    if (x != 'a') ++cnt;
    if (cnt > na / 2) break;
    s += x;
    if (x != 'a') s1 += x;
  }
  if (t == s + s1) {
    cout << s << endl;
  } else fail();
  return 0;
}