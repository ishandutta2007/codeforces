#include <stdio.h>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <bitset>
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

bitset<4000> v[2000];
bitset<2000> w[2000];
int n, m;

void out(bitset<4000> & v) {
  for (int i = 0; i < 2*n; ++i) cerr << v.test(i); cerr <<endl;
}

int main() {
  scanf("%d%d", &n, &m);
  vector<vii> q(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a; --b;
    v[b].set(a);
    q[a].push_back(pii(b, i));
  }
  for (int i = 0; i < n; ++i) {
    v[i].set(n + i);
//    out(v[i]);
  }
  bitset<4000> t;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) if (v[j].test(i)) {
      t = v[i];
      v[i] = v[j];
      v[j] = t;
//      v[i].swap(v[j]);
      break;
    }
//    for (int i = 0; i < n; ++i) out(v[i]); cerr << endl;
    for (int j = 0; j < n; ++j) if (j != i && v[j].test(i)) {
      v[j] ^= v[i];
    }
  }
  vi res(m);
  for (int i = 0; i < n; ++i) {
//    out(v[i]);
    for (int j = 0; j < n; ++j) if (v[i].test(n + j)) w[j].set(i);
  }
  for (int i = 0; i < n; ++i) {
    int t = 0;
    for (int j = 0; j < q[i].size(); ++j) {
      t ^= w[q[i][j].first].test(i);
    }
    for (int j = 0; j < q[i].size(); ++j) if (t ^ w[q[i][j].first].test(i)) {
      res[q[i][j].second] = 1;
    }
/*    bitset<2000> t;
    t.set(i);
    for (int j = 0; j < q[i].size(); ++j) {
      t ^= w[q[i][j].first];
    }
    for (int j = 0; j < q[i].size(); ++j) if (t.test(i) ^ w[q[i][j].first].test(i)) {
      res[q[i][j].second] = 1;
    }*/
  }
  for (int i = 0; i < res.size(); ++i) {
    if (res[i]) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}