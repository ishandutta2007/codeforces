#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

#define EPS 1e-10

const double INF = 1e50;

double myPow(double a, int b) {
  if (!b) return 0;
  if (fabs(a) < EPS) return -INF;
  return log(a) * b;
}

double S;
int a, b, c;
double by;

double getVal(double x, double y) {
  double z = S - x - y;
  return myPow(x, a) + myPow(y, b) + myPow(z, c);
}

double getMax(double x) {
  double L = 0, R = S - x;
  for (int step = 0; step < 200; step++) {
    double M1 = (2 * L + R) / 3;
    double M2 = (L + 2 * R) / 3;

    double v1 = getVal(x, M1);
    double v2 = getVal(x, M2);
    if (v1 < v2) L = M1;
    else R = M2;
  }
  by = (L + R) / 2;
  return getVal(x, by);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%lf%d%d%d", &S, &a, &b, &c) >= 1) {
    double L = 0, R = S;
    for (int step = 0; step < 200; step++) {
      double M1 = (2 * L + R) / 3;
      double M2 = (L + 2 * R) / 3;

      double v1 = getMax(M1);
      double v2 = getMax(M2);
      if (v1 < v2) L = M1;
      else R = M2;
    }
    double x = (L + R) / 2;
    getMax(x);
    printf("%.18e %.18e %.18e\n", x, by, S - x - by);
  }
  return 0;
}