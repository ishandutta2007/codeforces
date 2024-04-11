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

int f(int n) {
  int p2 = 0, p5 = 0;
  int n5 = n;
  while (n) {
    n /= 2;
    p2 += n;
  }
  while (n5) {
    n5 /= 5;
    p5 += n5;
  }
  return min(p2, p5);
}

int main() {
  int m;
  cin >> m;
  vi v;
  for (int n = 1; ; ++n) {
    int c = f(n);
    if (c > m) break;
    if (c == m) v.push_back(n);
  }
  cout << v.size() << endl;
  for (int x : v) printf("%d ", x);
  return 0;
}