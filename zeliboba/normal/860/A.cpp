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

vector<char> v = {'a', 'e', 'i', 'o', 'u'};

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  vi bad(256, 1);
  for (int x : v) {
    bad[x] = 0;
  }
  string t = "";
  for (char c : s) {
    if (t.size() >= 2 && bad[c] && bad[t[t.size() - 1]] && bad[t[t.size() - 2]] && (t[t.size() - 1] != c || t[t.size() - 2] != c)) {
      cout << t << ' ';
      t = "";
    }
    t += c;
  }
  cout << t << endl;
  return 0;
}