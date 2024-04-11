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
  vl v(2, 1);
  while (v.back() < 2e18) {
    v.push_back(v.back() + v[v.size() - 2]);
  }
  ll n; 
  cin >> n;
  int i = 1;
  while (n >= v[i+1]) ++i;
  cout << i - 1 << endl;
  return 0;
}