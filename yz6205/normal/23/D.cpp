// Copyright (C) 2020 JacderZhang
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef GEOMETRY_H_
#define GEOMETRY_H_ 1

#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Temps {

namespace Compare {

#ifndef GEOMETRY_H_EPS
#define GEOMETRY_H_EPS 1e-8
#endif 
constexpr double eps = GEOMETRY_H_EPS;

inline void testZero(double& a) { if (std::abs(a) <= eps) { a = 0; } }
inline bool equal(double a, double b) { return std::abs(b-a) <= eps; }
inline bool notEqual(double a, double b) { return std::abs(b-a) > eps; }
inline bool less(double a, double b) { return a+eps < b; }
inline bool less_equal(double a, double b) { return a <= b+eps; }
inline bool greater(double a, double b) { return a > b+eps; }
inline bool greater_equal(double a, double b) { return a+eps >= b; }
inline bool in_interval(double u, double l, double r) {
  if (l > r) { std::swap(l,r); }
  return greater_equal(u, l) && less_equal(u, r); }
inline bool in_interval_open(double u, double l, double r) {
  if (l > r) { std::swap(l,r); }
  return greater(u, l) && less(u, r); }
};

struct Point;
struct Circle;
struct Vector;
struct Line;
struct Segment;

struct Point {
  double x, y;
  explicit constexpr Point(double x=0, double y=0) : x(x), y(y) {}
  inline double distance(const Point& B) const {
    return std::sqrt( (x-B.x) * (x-B.x) + (y-B.y) * (y-B.y) ); }
  inline bool operator == (const Point& B) const {
    return Compare::equal(x, B.x) && Compare::equal(y, B.y); }
  inline bool isnop() const { return x == INFINITY && y == INFINITY; }
  inline Point add(const Vector& b) const;
  inline Point mid(const Point& b) const { return Point((x+b.x) / 2, (y+b.y) / 2); }
  inline bool operator < (const Point& b) const { return x == b.x ? y < b.y : x < b.x; }
  inline double getAngle() const { return atan2(y, x); }
  inline friend std::ostream& operator << (std::ostream& os, const Point& b) {
    os << "(" << b.x << "," << b.y << ")"; return os; }
};

struct Vector {
  double x, y;
  explicit constexpr Vector(double x=0, double y=0) : x(x), y(y) {}
  explicit constexpr Vector(const Point& a, const Point& b) : x(b.x-a.x), y(b.y-a.y) {} 
  explicit constexpr Vector(const Point& a) : x(a.x), y(a.y) {}
  explicit constexpr Vector(const Segment& a);
  inline double cross(const Vector& B) const { return x*B.y - y*B.x; }
  inline Vector mul(double p) const { return Vector(x*p, y*p); }
  inline double mul(const Vector& b) const { return x*b.x + y*b.y; }
  inline double getk() const { return y / x; }
  inline double length() const { return std::sqrt(x*x + y*y); }
  inline Vector rotater() const { return Vector(y, -x); }
  inline Vector rotatel() const { return Vector(-y, x); }
  inline Vector zoom(double newLen = 1) const {
    double factor = newLen / length();
    return Vector(x * factor, y * factor); }
  inline double degree(const Vector& b) const {
    return std::acos(mul(b) / (length() * b.length())); } 
};

inline Point Point::add(const Vector& b) const {
  return Point(x + b.x, y + b.y);
}

static constexpr Point nop = Point(INFINITY, INFINITY);

struct Line {
  Point origin; 
  Vector slope;
  explicit constexpr Line() =default;
  explicit constexpr Line(const Point& origin, const Vector& slope) : origin(origin), slope(slope) {}
  explicit constexpr Line(const Point& a, const Point& b) : origin(a), slope(Vector(a,b)) {}
  explicit constexpr Line(double k, double b) : origin(Point(0,b)), slope(Vector(1,k)) {}
  explicit constexpr Line(const Segment& b);
  inline bool cover(Point x) const {
    return Compare::equal( slope.cross(Vector(origin, x)), 0 ); }
  inline Point cross(const Line& b) const {
    double _x = Vector(origin, b.origin).cross(b.slope);
    double _y = slope.cross(b.slope);
    if (Compare::equal(_y, 0)) { return nop; }
    _x /= _y; return origin.add(slope.mul(_x)); }
  inline double getk() const { return slope.getk(); }
  inline double getb() const { return origin.y + (-origin.x) * getk(); }
  inline double distance(const Point& b) const {
    return cross(Line(b, slope.rotater())).distance(b); }
  inline double shadowLength(const Point& b) const {
    Point shadow = cross(Line(b, slope.rotater()));
    if (Compare::equal(slope.x, 0)) { return (shadow.y - origin.y) / slope.y; }
    return (shadow.x - origin.x) / slope.x; }
};

struct Segment {
  Point a, b;
  explicit Segment() =default;
  explicit Segment(Point a, Point b) : a(a), b(b) {}
  bool cover(Point x) {
    if (!Compare::in_interval(x.x, a.x, b.x) || 
        !Compare::in_interval(x.y, a.y, b.y)) { return false; }
    return Line(a,b).cover(x); }
  inline Line getPlumb() const {
    return Line(a.mid(b), Vector(a,b).rotater()); }
  inline Point mid() const { return a.mid(b); }
  inline double length() const { return Vector(a,b).length(); }
  inline bool isCross(const Segment& t) const {
    Point c = Line(*this).cross(Line(t));
    if (c.isnop()) { return false; }
    return Compare::in_interval(c.x, a.x, b.x) && Compare::in_interval(c.y, a.y, b.y) &&
           Compare::in_interval(c.x, t.a.x, t.b.x) && Compare::in_interval(c.y, t.a.y, t.b.y); 
  }
  inline bool isCross_open(const Segment& t) const {
    Point c = Line(*this).cross(Line(t));
    if (c.isnop()) { return false; }
    return Compare::in_interval_open(c.x, a.x, b.x) && Compare::in_interval_open(c.y, a.y, b.y) &&
           Compare::in_interval_open(c.x, t.a.x, t.b.x) && Compare::in_interval_open(c.y, t.a.y, t.b.y); 
  }
};

constexpr Line::Line(const Segment& b) : origin(b.a), slope(Vector(b.a, b.b)) {}
constexpr Vector::Vector(const Segment& a) : x(a.b.x - a.a.x) , y(a.b.y - a.a.y) {}

std::vector<Point>
getConvex(std::vector<Point> ps) {
  if (ps.size() <= 2) { return ps; }
  std::sort(ps.begin(), ps.end(), [](Point a, Point b) { 
    return a.x == b.x ? a.y < b.y : a.x < b.x; }); 
  ps.erase(std::unique(ps.begin(), ps.end()), ps.end());
  std::vector<Point> res;
  for (Point p: ps) {
    while (res.size() >= 2) {
      Point &a = res[res.size()-2], &b = res.back();
      if (Compare::less_equal(Vector(b,p).cross(Vector(b,a)),0)) { break; } 
      res.pop_back(); }
    res.push_back(p); }
  res.pop_back();
  std::size_t osize = res.size();
  std::reverse(ps.begin(), ps.end());
  for (Point p: ps) {
    while (res.size() - osize >= 2) {
      Point &a = res[res.size()-2], &b = res.back();
      if (Compare::less_equal(Vector(b,p).cross(Vector(b,a)),0)) { break; }
      res.pop_back(); }
    res.push_back(p); }
  res.pop_back();
  return res;
}

double getPerimeter(std::vector<Point> ps) {
  std::size_t sz = ps.size();
  double ans = 0;
  for (std::size_t i=0; i<sz; ++i) {
    ans += ps[i].distance(ps[(i+1)%sz]); }
  return ans; }

struct Circle {
  Point o; double r;
  Circle() =default;
  explicit constexpr Circle(const Point& o, double r) : o(o), r(r) {}
  explicit Circle(const Point& a, const Point& b, const Point& c) :
    o(Segment(a,b).getPlumb().cross(Segment(b,c).getPlumb())),
    r(o.distance(a)) {}
  inline bool cover(const Point& p) const { return Compare::less_equal(o.distance(p), r); }
  inline double perimeter() const { return 2 * M_PI * r; }
};

} /* Temps */

#endif
using namespace Temps;


#ifndef SCANNER_H_
#define SCANNER_H_ 1
#include <stdio.h>
#include <stdlib.h>
class Scanner
{
private:
  static const int BUFFER_SIZE = 10000;
  char buff[BUFFER_SIZE];
  int buffPos, buffLim;

public:
  Scanner()
  {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    buffPos = 0;
  }

private:
  inline void flushBuff()
  {
    buffLim = fread(buff, 1, BUFFER_SIZE, stdin);
    if (buffLim == 0) {
      buff[buffLim++] = '\n';
    }
    buffPos = 0;
  }
  inline bool isWS(char t) { return t <= ' '; }
  inline bool isDig(char t) { return t >= '0' && t <= '9'; }
  void nextPos()
  {
    buffPos++;
    if (buffPos == buffLim) {
      flushBuff();
    }
  }
#define getChar() buff[buffPos]
public:
  inline char getchar()
  {
    char ch = getChar();
    nextPos();
    return ch;
  }
  inline void next(char* s)
  {
    while (isWS(getChar())) {
      nextPos();
    }
    while (!isWS(getChar())) {
      *s = getChar();
      s++;
      nextPos();
    }
    *s = '\0';
  }
  inline void nextLine(char* s)
  {
    while (getChar() != '\n') {
      nextPos();
    }
    if (getChar() == '\n') {
      nextPos();
    }
    while (getChar() != '\n') {
      *s = getChar();
      s++;
      buffPos++;
    }
    *s = '\0';
  }
  inline int nextInt()
  {
    while (!isDig(getChar()) && getChar() != '-') {
      nextPos();
    }
    int sign = (getChar() == '-') ? nextPos(), -1 : 1;
    int res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    return res * sign;
  }
  inline long long nextLong()
  {
    while (!isDig(getChar()) && getChar() != '-') {
      nextPos();
    }
    long long sign = (getChar() == '-') ? nextPos(), -1 : 1;
    long long res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    return res * sign;
  }
  inline int n()
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    int res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = res * 10 + (getChar() - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nl()
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = res * 10 + (getChar() - '0');
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline long long nlm(const int MOD)
  {
    while (getChar() < '0' || getChar() > '9') {
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    long long res = 0;
    while (getChar() >= '0' && getChar() <= '9') {
      res = (res * 10 + (getChar() - '0')) % MOD;
      buffPos++;
      if (buffPos == buffLim) {
        flushBuff();
      }
    }
    return res;
  }
  inline double nextDouble()
  {
    while (isWS(getChar())) {
      nextPos();
    }
    int sign = (getChar() == '-') ? nextPos(), -1 : 1;
    double res = 0;
    while (isDig(getChar())) {
      res = res * 10 + getChar() - '0';
      nextPos();
    }
    if (getChar() == '.') {
      nextPos();
      double ep = 1;
      while (isDig(getChar())) {
        ep *= 0.1;
        res += ep * (getChar() - '0');
        nextPos();
      }
    }
    return sign * res;
  }
  inline char nextChar()
  {
    while (isWS(getChar()))
      nextPos();
    char res = getChar();
    nextPos();
    return res;
  }
#undef getChar
};
Scanner sc;
#endif /* SCANNER_H_ */
#ifndef LOG_H_
#define LOG_H_ 1

#ifdef __LOCALE__

#include <iostream>
template<typename T>
void
__ses(T a)
{
  std::cout << a << " ";
}
template<typename T, typename... Args>
void
__ses(T a, Args... b)
{
  std::cout << a << " ";
  __ses(b...);
}
#define ses(...)                                                               \
  {                                                                            \
    std::cout << #__VA_ARGS__ << " = ";                                        \
    __ses(__VA_ARGS__);                                                        \
  }
#define see(...)                                                               \
  {                                                                            \
    ses(__VA_ARGS__);                                                          \
    std::cout << std::endl;                                                    \
  }
#define slog(format, ...) printf(format "\n", __VA_ARGS__)

template<class _Type>
void
logArray(_Type a[], int n)
{
  for (int i = 0; i < n; ++i)
    std::cout << a[i] << ' ';
  std::cout << std::endl;
}

#else

#define see(...)
#define ses(...)
#define slog(format, ...)
template<class _Type>
void
logArray(_Type a[], int n)
{}

#endif

#endif /* LOG_H_ */
#ifndef LOOP_H_
#define LOOP_H_ 1

#define repe(a, b) for (int a = 0; a < (int)b.size(); a++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define repa(i, n) for (int i = 1; i <= n; i++)
#define repi(i, a, b) for (int i = a; i <= b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)

#endif /* LOOP_H_ */
#ifndef BASE_H_
#define BASE_H_ 1

template<class T>
inline bool
checkMin(T& a, T b)
{
  return (a > b ? a = b, 1 : 0);
}
template<class T>
inline bool
checkMax(T& a, T b)
{
  return (a < b ? a = b, 1 : 0);
}

#endif /* BASE_H_ */
// #include "/home/jack/code/creats/STree.h"
// #include "/home/jack/code/creats/Tree.h"
// #include "/home/jack/code/creats/Graph.h"
// #include "/home/jack/code/creats/Intm.h"
// #include "/home/jack/code/Math/Poly/main.h"

#include <bits/stdc++.h>

#define MULTIPLE_TEST_CASES_WITH_T
// #define MULTIPLE_TEST_CASES_WITHOUT_T
#ifndef _BODY_MAIN
#define _BODY_MAIN 1

#ifndef CUSTOM_MAIN
void
preInit();
void
init();
void
solve();
int32_t
main()
{
  preInit();
#ifdef MULTIPLE_TEST_CASES_WITH_T
  int T;
#ifdef SCANNER_H_
  T = sc.nextInt();
#else
  scanf("%d", &T);
#endif /* SCANNER_H_ */
  while (T--) {
    init();
    solve();
  }
#else
#ifdef MULTIPLE_TEST_CASES_WITHOUT_T
  while (1) {
    try {
      init();
    } catch (bool t) {
      return 0;
    }
    solve();
  }
#else
  init();
  solve();
#endif /* MULTIPLE_TEST_CASES_WITHOUT_T  */
#endif /* MULTIPLE_TEST_CASES_WITH_T */
  return 0;
}
#endif /* CUSTOM_MAIN */

#endif /* _BODY_MAIN */
// #define int long long

/** My code begins here **/

Point nextPoint() {
  int x=sc.n(), y=sc.n(); return Point(x, y); }

bool valid(Point a, Point b, Point c, Point d) {
  Vector A = Vector(a,b);
  Vector B = Vector(b,c);
  Vector C = Vector(c,d);
  Vector D = Vector(d,a);
  double crossA = A.cross(B);
  double crossB = B.cross(C);
  double crossC = C.cross(D);
  double crossD = D.cross(A);
  if (Compare::equal(crossA, 0) ||
      Compare::equal(crossB, 0) ||
      Compare::equal(crossC, 0) ||
      Compare::equal(crossD, 0) ) {
    return false; }
  bool signA = crossA > 0;
  bool signB = crossB > 0;
  bool signC = crossC > 0;
  bool signD = crossD > 0;
  return signA == signB && signB == signC && signC == signD;
}

bool attempt(Point m, Point a, Point b) {
  Point b2 = m.add(Vector(b,m));
  Point B = Circle(a,m,b2).o;
  Point A = a.add(Vector(B,a));
  Point C = m.add(Vector(B,m));
  Point D = b.add(Vector(b2,B));
  if (valid(A, B, C, D)) {
    puts("YES");
    printf("%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n",
           A.x, A.y, B.x, B.y, C.x, C.y, D.x, D.y);
    return true; }
  return false; }
  
void preInit() { } void init() {
} void solve() {
  Point A=nextPoint(), B=nextPoint(), C=nextPoint();
  if (Compare::equal(Vector(A, B).cross(Vector(A,C)), 0)) {
    puts("NO\n"); return; }
  if (attempt(A, B, C)) { return; }
  if (attempt(B, C, A)) { return; }
  if (attempt(C, A, B)) { return; }
  puts("NO\n");
}