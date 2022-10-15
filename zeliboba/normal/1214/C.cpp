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

bool f(string s) {
  int mi = 0, sum = 0;
  for (char x : s) {
    sum += x == '(' ? 1 : -1;
    mi = min(mi, sum);
  }
  return mi >= -1;
}

int main() {
  //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  string s1 = s;
  reverse(s.begin(), s.end());
  int c = 0;
  for (int i = 0; i < s.size(); ++i) {
    s[i] = s[i] == ')' ? '(' : ')';
    c += s[i] == ')';
  }
  if (c * 2 == n && (f(s) || f(s1))) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}