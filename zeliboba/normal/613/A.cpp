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

struct pt {
  double x,y;
};

double p2(double x) {
  return x*x;
}

double sc(pt a, pt b) {
  return a.x*b.x + a.y*b.y;
}

int main() {
  int n;
  cin >> n;
  pt p;
  scanf("%lf%lf", &p.x, &p.y);
  vector<pt> x(n);
  double ma = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lf%lf", &x[i].x, &x[i].y);
    x[i].x -= p.x;
    x[i].y -= p.y;
    ma = max(ma, sc(x[i], x[i]));
  }
  x.push_back(x[0]);
  double mi = ma;
  for (int i = 0; i < n; ++i) {
    mi = min(mi, sc(x[i], x[i]));
    double a = sqrt(sc(x[i], x[i]));
    double b = sqrt(sc(x[i+1], x[i+1]));
    double c = sqrt(p2(x[i].x - x[i+1].x) + p2(x[i].y - x[i+1].y));
    double s = abs(x[i].x*x[i+1].y - x[i].y*x[i+1].x);
    if (p2(a) < p2(b)+p2(c) && p2(b) < p2(a)+p2(c)) {
      mi = min(mi, p2(s / c));
    }
  }
  printf("%.10lf\n", acos(-1)*(ma - mi));
  return 0;
}