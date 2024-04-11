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
  scanf("%d", &n);
  vi erat(n + 2, 1);
  for (int i = 2; i * i < erat.size(); ++i) if (erat[i])
    for (int j = i * i; j < erat.size(); j += i) erat[j] = 0;
  vi res(n);
  int k = 1;
  for (int i = 0; i < n; ++i) {
    res[i] = 2 - erat[i + 2];
    k = max(k, res[i]);
  }
  printf("%d\n", k);
  for (int i = 0; i < n; ++i) printf("%d ", res[i]);
  return 0;
}