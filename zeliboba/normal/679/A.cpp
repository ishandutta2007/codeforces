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
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
  vi p;
  for (int i = 2; i < 100; ++i) {
    bool ok = 1;
    for (int j = 2; j * j <= i; ++j) if (i % j == 0) {
       ok = 0;
       break;
    }
    if (ok) p.push_back(i);
  }
  int c = 0;
  for (int i = 0; p[i] < 50; ++i) {
    cout << p[i] << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s[0] == 'y') ++c;
  }
  for (int i = 0; p[i] < 10; ++i) {
    cout << p[i]*p[i] << endl;
    fflush(stdout);
    string s;
    cin >> s;
    if (s[0] == 'y') c += 2;
  }
  if (c > 1) cout << "composite\n";
  else cout << "prime\n";
  fflush(stdout);
  return 0;
}