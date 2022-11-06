#include <cassert>
#include <cstring>

#include <cstdio>
#include <cstdlib>

#include <algorithm>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Inter {
  double a, b;
  friend Inter operator + (Inter A, Inter B) {
    return {A.a+B.a, A.b+B.b};
  }
  friend Inter operator * (Inter A, Inter B) {
    vector<double> v;

    for (auto x : A.get())
      for (auto y : B.get())
        v.push_back(x * y);

    sort(v.begin(), v.end());
    return {v[0], v.back()};
  }
  vector<double> get() {
    vector<double> ans = {a, b};
    if (a <= 0 && 0 <= b) ans.push_back(0);
    return ans;
  }
};

double a, b, c, d;

bool solve(double r) {
  Inter A{a-r, a+r}, B{b-r, b+r}, C{c-r, c+r}, D{d-r, d+r};
  Inter tmp = A*D + B*C*(Inter){-1, -1};
  return tmp.a <= 0 && 0 <= tmp.b;
}

int main(void) {
  cin >> a >> b >> c >> d;
  
  double lo = 0, hi = 1e10;
  REP(iter, 200) {
    double mid = (lo + hi) / 2;
    if (solve(mid))
      hi = mid;
    else
      lo = mid;
  }
  printf("%.12lf\n", (lo+hi)/2);

  return 0;
}