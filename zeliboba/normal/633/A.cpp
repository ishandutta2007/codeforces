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
  int a,b,c;
  cin >> a >> b >> c;
  vi d(c + 1);
  for (int i = 0; i <= c; i += a) d[i] = 1;
  for (int i = 0; i + b <= c; ++i) if (d[i]) d[i+b] = 1;
  if (d[c]) cout << "Yes\n";
  else cout << "No\n";
  return 0;
}