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

bool run(const vi & a, multiset<int> & w, int & res) {
  vi v(a.size());
  for (int i = 0; i < a.size(); ++i) {
    auto it = w.upper_bound(a[i]);
    if (it == w.begin()) {
      for (int j = 0; j < i; ++j) w.insert(v[j]);
      return false;
    }
    --it;
    v[i] = *it;
    w.erase(it);
  }
  ++res;
//  cerr << w.size() << ' ' << res << endl;
  return true;
}

void f(vi a, multiset<int> & w, int & res) {
  sort(a.begin(), a.end());
  while (run(a, w, res)) {}
//  cerr << w.size() << ' ' << res << endl;
}

void g(multiset<int> & w, int t) {
  auto it = w.upper_bound(t);
  if (it != w.begin()) {
    --it;
    w.erase(it);
  }
}

int main() {
  int n;
  vi a(3);
  while (cin >> n >> a[0] >> a[1] >> a[2]) {
  sort(a.begin(), a.end());
  vi v(n);
  for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
  sort(v.begin(), v.end());
  if (v.back() > a[0]+a[1]+a[2]) {
    cout << -1 << endl;
    continue;
  }
  int res = 0;
  while (!v.empty() && v.back() > a[1] + a[2]) {
    assert(v.back() <= a[0]+a[1]+a[2]);
    v.pop_back();
    ++res;
  }
  multiset<int> w;
  for (int i = 0; i < v.size(); ++i) w.insert(v[i]);
  while (!w.empty() && *(--w.end()) > a[0] + a[2]) {
    w.erase(--w.end());
    if (!w.empty()) g(w, a[0]);
    ++res;
  }
  while (!w.empty() && *(--w.end()) > max(a[0] + a[1], a[2])) {
    w.erase(--w.end());
    if (!w.empty()) g(w, a[1]);
    ++res;
  }
  while (!w.empty() && *(--w.end()) > a[2]) {
    w.erase(--w.end());
    if (!w.empty()) g(w, a[2]);
    ++res;
  }
  vi b(2);
/*  while (!w.empty()) {
    int t = max(a[2], a[0] + a[1]);
    auto it = w.end(); --it;
    if (*it <= t) break;
    b[0] = a[1]; b[1] = a[2] + a[0];
    if (!run(b, w, res)) break;
  }*/
  f(a, w, res);
/*  b[0] = a[0]; b[1] = a[2] + a[1];
  f(b, w, res);
  b[0] = a[1]; b[1] = a[0] + a[2];
  f(b, w, res);*/
  b[0] = a[2]; b[1] = a[0] + a[1];
  f(b, w, res);
  cout << res + w.size() << endl;
  }
  return 0;
}