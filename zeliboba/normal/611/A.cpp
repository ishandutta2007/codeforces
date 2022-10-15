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
  int n;
  string a,b;
  cin >> n >> a >> b;
  if (b[0] == 'm') {
    if (n <= 29) cout << 12 << endl;
    else if (n <= 30) cout << 11 << endl;
    else cout << 7 << endl;
  } else {
    if (n == 5 || n == 6) cout << 366 / 7 + 1 << endl;
    else cout << 366 / 7 << endl;
  }
  return 0;
}