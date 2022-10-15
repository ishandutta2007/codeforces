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
const int mod = 1000000007;

char s[1100000];
int main() {
  int n, k;
  scanf("%d%d%s", &n, &k, s);
  int m = strlen(s);
  ll all = 1;
  vi v(k);
  vi last(k);
  for (int i = 0; i < m; ++i) {
    int ind = s[i] - 'a';
    last[ind] = i + 1;
    ll nv = all;
    all = (all - v[ind] + nv + mod) % mod;
    v[ind] = nv;
//    cerr << all << endl;
  }
  for (int t = 0; t < n; ++t) {
    int mi = last[0], ind = 0;
    for (int i = 0; i < k; ++i) if (last[i] < mi) {
      mi = last[i];
      ind = i;
    }
    last[ind] = m + t + 1;
    ll nv = all;
    all = (all - v[ind] + nv + mod) % mod;
    v[ind] = nv;
/*    ll nv = (all - v[ind].first + mod) % mod;
    all = (all - v[ind].first + nv + mod) % mod;
    v[ind].first = v[ind].second;
    v[ind].second = nv;*/
/*    ll nv = (all - v[ind] + mod) % mod;
    all = (all - v[ind] + nv + mod) % mod;
    v[ind] = nv;*/
  }
  cout << (all % mod + mod) % mod << endl;
  return 0;
}