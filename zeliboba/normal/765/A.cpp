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
  int n;
  string s0;
  cin >> n >> s0;
//  map<string, int> w;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
//    w[s.substr(0, 3)] += 1;
//    w[s.substr(5, 3)] -= 1;
  }
  if (n % 2) {
    cout << "contest\n";
  } else {
    cout << "home\n";
  }
//  for (auto x : w) {
    
//  }
  return 0;
}