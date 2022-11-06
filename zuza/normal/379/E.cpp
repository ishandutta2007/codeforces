#include <algorithm>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); ++i)
#define TRACE(x) cout << #x << " = " << (x) << endl

typedef long long llint;

typedef pair<double, double> point;
#define X first
#define Y second

const double eps = 1e-8;

double sgn(double x) { return (x > eps) - (x < -eps); }

int ccw(point a, point b, point c) {
  double sum = 0;
  sum += a.X * (b.Y - c.Y);
  sum += b.X * (c.Y - a.Y);
  sum += c.X * (a.Y - b.Y);
  return sgn(sum);
}

struct Line {
  double a, b, c;

  friend double mixed(Line a, Line b, Line c) {
    double sum = 0;
    sum += a.a*b.b*c.c;
    sum += b.a*c.b*a.c;
    sum += c.a*a.b*b.c;
    sum -= a.c*b.b*c.a;
    sum -= b.c*c.b*a.a;
    sum -= c.c*a.b*b.a;
    return sgn(sum);
  }

  friend Line cross(Line a, Line b) {
    return {a.b*b.c - a.c*b.b
        ,   a.c*b.a - b.c*a.a
        ,   a.a*b.b - a.b*b.a};
  }
};

struct Normal {
  double x, y;

  Normal(double x, double y) : x(x), y(y) {}
  Normal(Line p) { x = p.a; y = p.b; }

  friend int ccw(Normal a, Normal b, Normal c) {
    int sum = 0;
    sum += a.x * (b.y - c.y);
    sum += b.x * (c.y - a.y);
    sum += c.x * (a.y - b.y);
    return (sum > eps) - (sum < -eps);
  }
};

struct Area {
  vector<Line> data;

  void clear() { data.clear(); }

  void insert(Line p) {
    auto normal_cmpf = [](Line a, Line b){ // sortiraj pravce po normali (pretpostavlja y >= 0)
      Normal na = Normal(a), nb = Normal(b);
      if (sgn(na.x) != sgn(nb.x)) return sgn(na.x) > sgn(nb.x);
      return ccw(Normal(0, 0), na, nb) > 0;
    };

    data.insert(lower_bound(data.begin(), data.end(), p, normal_cmpf), p); // sorted insertion
    build_envelope(); /// ne zovi uvijek? !!!
  }

  void build_envelope() { // sto ako su zadnja dva paralelna?
    int sz = min((int)data.size(), 2);

    for (int i = sz; i < (int)data.size(); ++i) {
      while (sz >= 2 && mixed(data[sz-2], data[sz-1], data[i]) < eps)
        --sz;
      if (sz != i) data[sz] = data[i];
      ++sz;
    }
    data.resize(sz);
  }

  double get_area() { // povrsina iznad x-osi
    struct Point { double x, y; };

    Point last;
    double a2 = 0;

    for (int i = 1; i < (int)data.size(); ++i) {
      Line inter = cross(data[i-1], data[i]);
      assert(fabs(inter.c) > eps); // nije 0
      Point nov = {inter.a / inter.c, inter.b / inter.c};

      if (i > 1) {
        a2 += (nov.x - last.x) * (nov.y + last.y); // integriraj [last.x, last.y]
      }
      last = nov;
    }

    return a2 / 2.0;
  }
};

int main_area_test(void)
{
  Area area;
  area.insert({1, 0, 0});  //  1x + 0y +  0 = 0
  area.insert({0, 1, -1}); //  0x + 1x + -1 = 0
  area.insert({-1, 0, 1}); // -1x + 0x +  1 = 0
  TRACE(area.get_area());

  area.insert({-1, 1, -0.5}); // -x + y + -0.5 = 0
  TRACE(area.get_area());  

  area.clear();
  return 0;
}

int main(void) {
  int n, k; scanf("%d %d", &n, &k);

  const int MAXN = 300 + 123;
  const int MAXK = 300 + 123;

  static int ys[MAXN][MAXK];
  static double sol[MAXN] = {0};

  REP(i, n) REP(j, k+1) scanf("%d", ys[i]+j);

  REP(j, k) {
    static Area area; area.clear();
    area.insert({1, 0, 0});
    double last_area = 0;
    REP(i, n) {
      double dx = 1;
      double dy = ys[i][j+1] - ys[i][j];
      double a = -dy;
      double b = dx;
      double c = -(a*0 + b*ys[i][j]);
      assert(fabs(a*1 + b*ys[i][j+1] + c) < eps);
      area.insert({a, b, c});
      area.insert({-1, 0, 1});
      double now_area = area.get_area();
      area.data.pop_back();
      sol[i] += now_area - last_area;
      last_area = now_area;
    }
  }

  REP(i, n) printf("%.9lf\n", sol[i]);
  return 0;
}